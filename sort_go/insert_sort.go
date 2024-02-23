package main

import "fmt"

func InsertSort(arr []int) {
	for j := 1; j < len(arr); j++ {
		curIdx := j
		curNum := arr[j]
		for ; curIdx > 0 && arr[curIdx-1] > curNum; curIdx-- {
			arr[curIdx] = arr[curIdx-1]
		}
		arr[curIdx] = curNum
	}
}

func main() {
	arr := []int{7, 1, 4, 6, 9, 2, 5, 3}
	InsertSort(arr)
	fmt.Println(arr)

	arr = []int{1, 2, 1, 1, 1, 1, 2}
	InsertSort(arr)
	fmt.Println(arr)

	arr = []int{}
	InsertSort(arr)
	fmt.Println(arr)

}
