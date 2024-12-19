package main

import (
	"Rebrain/go-base_final/internal"
	"bufio"
	"context"
	"fmt"
	"os"
	"time"
)

func main() {
	ctx, cancelFunc := context.WithCancel(context.Background())
	dn := internal.NewStrDS()
	if err := dn.ScanDir(); err != nil {
		return
	}

L:
	for {
		go func() {
			internal.Spinner()
			if bufio.NewScanner(os.Stdin).Scan() {
				cancelFunc()
			}
		}()
		select {
		case <-time.Tick(time.Millisecond * 1000):
			internal.Wg.Add(1)
			go func() {
				if err := dn.SyncFile(); err != nil {
					cancelFunc()
				}
			}()
		case <-ctx.Done():
			break L
		}
		internal.Wg.Wait()
	}
	fmt.Println("File synchronization completed")
}
