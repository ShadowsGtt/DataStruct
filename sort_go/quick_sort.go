package main

import (
	"fmt"
	"math"
)

func QuickSort(arr []int) {
	fmt.Println("partition: ", arr)
	if len(arr) <= 1 {
		return
	}
	base := partition(arr)
	QuickSort(arr[:base])
	QuickSort(arr[base+1:])
	//time.Sleep(time.Second * 3)
}

func partition(arr []int) int {
	if len(arr) <= 1 {
		return 0
	}
	head := 0
	tail := len(arr) - 1
	mid := int(math.Ceil(float64(tail-head) / 2))

	base := arr[mid]
	//fmt.Printf("base: arr[%d]=%d\n", mid, base)
	for head < tail {
		for arr[head] < base {
			head++
		}
		for arr[tail] > base {
			tail--
		}
		//fmt.Printf("交换: arr[%d]=%d, arr[%d]=%d\n", head, tail, arr[head], arr[tail])
		arr[head], arr[tail] = arr[tail], arr[head]
	}
	return head
}

func main() {
	arr := []int{2, 9, 3, 7, 8, 6, 4}
	QuickSort(arr)
	fmt.Println(arr)
}
