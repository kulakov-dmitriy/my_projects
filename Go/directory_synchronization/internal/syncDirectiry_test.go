package internal

import (
	"bytes"
	"os"
	"strings"
	"testing"
)

func Test_syncFile(t *testing.T) {
	Wg.Add(55)
	dn := NewStrDS()
	dn.SourceDir = "testDir/dir1"
	dn.CopiesDir = "testDir/dir2"
	dn.SyncFile()
	create, _ := os.Create("testDir/dir1/44.txt")
	dn.SyncFile()
	//проверка на наличие файла 44.txt
	if FileIsNotExist("testDir/dir2/44.txt") {
		t.Error()
	}
	//записываем в файл testDir/dir1/44.txt строку "Hello"
	if _, err := create.WriteString("Hello"); err != nil {
		t.Error(err)
	}
	dn.SyncFile()
	dn.SyncFile()
	file, _ := os.ReadFile("testDir/dir2/44.txt")
	//провевяем, совпадает ли запись в testDir/dir2/44.txt с "Hello"
	if !strings.Contains(string(file), "Hello") {
		t.Error()
	}
	//меняем запись в файле testDir/dir1/44.txt на строку "World"
	err := os.WriteFile("testDir/dir1/44.txt", []byte("World"), os.ModePerm)
	if err != nil {
		return
	}
	dn.SyncFile()
	dn.SyncFile()
	//провевяем, совпадает ли запись в testDir/dir2/44.txt с "World"
	if readFile, err := os.ReadFile("testDir/dir2/44.txt"); err != nil || !bytes.Contains(readFile, []byte("World")) {
		t.Error(err)
	}
	//меняем имя файла
	os.Rename("testDir/dir1/44.txt", "testDir/dir1/4.txt")
	// проверка на наличие файла 4.txt и отсутствие 44.txt в директории testDir/dir2
	if err := dn.SyncFile(); err != nil || !FileIsNotExist("testDir/dir2/44.txt") || FileIsNotExist("testDir/dir2/4.txt") {
		t.Error()
	}
	os.MkdirAll("testDir/dir1/dir3", os.ModePerm)
	dn.SyncFile()
	//проверка на наличие testDir/dir2/dir3
	if FileIsNotExist("testDir/dir2/dir3") {
		t.Error()
	}
	os.RemoveAll("testDir/dir1/dir3")
	dn.SyncFile()
	//проверка на отсутствие testDir/dir2/dir3
	if !FileIsNotExist("testDir/dir2/dir3") {
		t.Error()
	}
	//удаляем тестовые файлы
	os.RemoveAll("testDir")
	os.RemoveAll("info.log")
}

func BenchmarkName(b *testing.B) {
	dn := NewStrDS()
	dn.SourceDir = "testDir/dir1"
	dn.CopiesDir = "testDir/dir2"
	for i := 0; i < b.N; i++ {
		Wg.Add(1)
		go dn.SyncFile()
		Wg.Wait()
	}
	os.RemoveAll("testDir")
	os.RemoveAll("info.log")
}
