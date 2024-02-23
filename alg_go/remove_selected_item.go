package main

import "fmt"

func RemoveSelectedItem(arr []int, item int) int {
	if len(arr) == 0 {
		return 0
	}

	slow, fast := 0, 0
	for fast < len(arr) {
		if arr[fast] == item {
			fast++
			continue
		}
		arr[slow] = arr[fast]
		slow++
		fast++
	}
	return slow
}

func main() {
	arr := []int{7, 2, 1, 7, 5, 6, 7}
	n := RemoveSelectedItem(arr, 9)
	fmt.Println(arr[:n])
}
