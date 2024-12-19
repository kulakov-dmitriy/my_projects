package internal

import (
	"bytes"
	"crypto/md5"
	"fmt"
	"io"
	"io/fs"
	"log"
	"os"
	"path/filepath"
	"sync"
	"time"
)

type logger struct {
	logInfo  log.Logger
	logError log.Logger
}
type dirSync struct {
	SourceDir string
	CopiesDir string
	*logger
}

var Wg = sync.WaitGroup{}

func NewStrDS() *dirSync {
	file, _ := os.OpenFile("info.log", os.O_RDWR|os.O_CREATE|os.O_TRUNC, os.ModePerm)
	return &dirSync{
		logger: &logger{
			logInfo:  *log.New(file, "INFO\t", log.Ldate|log.Ltime),
			logError: *log.New(file, "ERROR\t", log.Ldate|log.Ltime|log.Llongfile),
		},
	}
}
func (dn *dirSync) SyncFile() error {
	defer Wg.Done()
	if FileIsNotExist(dn.SourceDir) {
		dn.logInfo.Printf("\tCreate directory:\t%s", dn.SourceDir)
		os.MkdirAll(dn.SourceDir, os.ModePerm)
	}
	if err := filepath.Walk(dn.SourceDir, func(path string, info fs.FileInfo, err error) error {
		rel, err := filepath.Rel(dn.SourceDir, path)
		if err != nil {
			return err
		}

		joinCD := filepath.Join(dn.CopiesDir, rel)
		joinSD := filepath.Join(dn.SourceDir, rel)

		if FileIsNotExist(joinCD) {
			if info.IsDir() {
				dn.logInfo.Printf("\tCreate directory:\t%s\t", joinCD)
				err := os.MkdirAll(joinCD, os.ModePerm)
				if err != nil {
					return err
				}
			} else {
				dn.logInfo.Printf("\tCreate file:\t%s\tSize:%d", joinCD, info.Size())
				err := createFile(joinCD, joinSD)
				if err != nil {
					return err
				}
			}
			return nil
		}
		if b, err := fileComparison(joinSD, joinCD); !b && !info.IsDir() {
			if err != nil {
				return err
			}
			dn.logInfo.Printf("\tModified file:\t%s\tSize:%d", joinSD, info.Size())
			err = os.Remove(joinCD)
			if err != nil {
				return err
			}
		}
		return nil
	}); err != nil {
		dn.logError.Print(err)
		return err
	}
	if err := dn.deleteFile(); err != nil {
		dn.logError.Print(err)
		return err
	}
	return nil
}
func fileComparison(joinSD, joinCD string) (b bool, err error) {
	openJM, err := os.Open(joinSD)
	if err != nil {
		return false, err
	}
	defer openJM.Close()
	openJO, err := os.Open(joinCD)
	if err != nil {
		return false, err
	}
	defer openJO.Close()
	_, err = openJM.Seek(0, 0)
	if err != nil {
		return false, err
	}
	_, err = openJO.Seek(0, 0)
	if err != nil {
		return false, err
	}
	hash, hash2 := md5.New(), md5.New()
	_, err = io.Copy(hash, openJM)
	if err != nil {
		return false, err
	}
	_, err = io.Copy(hash2, openJO)
	if err != nil {
		return false, err
	}
	return bytes.Equal(hash.Sum(nil), hash2.Sum(nil)), nil
}

func createFile(joinCD, joinSD string) error {
	create, err := os.Create(joinCD)
	if err != nil {
		return err
	}
	defer create.Close()
	open, err := os.Open(joinSD)
	if err != nil {
		return err
	}
	defer open.Close()
	_, err = create.ReadFrom(open)
	if err != nil {
		return err
	}
	return nil
}
func (dn *dirSync) deleteFile() error {
	return filepath.Walk(dn.CopiesDir, func(path string, info fs.FileInfo, err error) error {
		rel, err := filepath.Rel(dn.CopiesDir, path)
		if err != nil {
			return err
		}
		joinMain := filepath.Join(dn.SourceDir, rel)
		if FileIsNotExist(joinMain) {
			if info.IsDir() {
				dn.logInfo.Printf("\tDelete directory:\t%s", path)
				err = os.RemoveAll(path)
				if err != nil {
					return err
				}
				return filepath.SkipDir
			} else {
				dn.logInfo.Printf("\tDelete file:\t%s\tSize:%d", path, info.Size())
				err = os.Remove(path)
				if err != nil {
					return err
				}
			}
		}
		return nil
	})
}

func FileIsNotExist(dir string) bool {
	_, err := os.Stat(dir)
	return os.IsNotExist(err)
}
func Spinner() {
	for _, s := range []string{"-", "\\", "|", "/"} {
		fmt.Print("\rStart file synchronization ", s)
		time.Sleep(time.Millisecond * 150)
	}
}
func (dn *dirSync) ScanDir() error {
	fmt.Print("Enter the source directory path: ")
	if _, err := fmt.Scan(&dn.SourceDir); err != nil {
		dn.logError.Print(err)
		return err
	}
	fmt.Print("Enter the path of the copy of the source directory: ")
	if _, err := fmt.Scan(&dn.CopiesDir); err != nil {
		dn.logError.Print(err)
		return err
	}
	fmt.Println("Press Enter to end the program")
	return nil
}
