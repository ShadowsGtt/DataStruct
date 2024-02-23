package main

import "fmt"

func RemoveSortedArrDupItem(arr []int) int {
	if len(arr) <= 1 {
		return len(arr)
	}
	head := 0
	for i := 1; i < len(arr); i++ {
		if arr[i] == arr[head] {
			continue
		}
		head = head + 1
		arr[head] = arr[i]
	}
	return head + 1
}

func main() {
	arr := []int{1, 1, 2, 3, 4, 4, 5, 6, 7, 7, 7, 8, 9, 10}
	l := RemoveSortedArrDupItem(arr)
	fmt.Println(arr[:l])

}
