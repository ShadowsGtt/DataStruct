package main

import (
	"fmt"
	"math"
)

func BinarySearch(arr []int, key int) int {
	if len(arr) <= 0 {
		return math.MaxInt
	}
	head := 0
	tail := len(arr) - 1
	if key < arr[head] {
		return math.MaxInt
	}
	if key > arr[tail] {
		return math.MaxInt
	}

	for head <= tail {
		mid := (head + tail) / 2
		fmt.Println(head, mid, tail)
		if key == arr[mid] {
			return mid
		} else if key > arr[mid] {
			head = mid + 1
		} else if key < arr[mid] {
			tail = mid - 1
		}
	}

	return math.MaxInt
}

func main() {
	arr := []int{1, 2, 3, 4, 6, 7, 8}

	fmt.Println(BinarySearch(arr, 8))

}
