package main

import "fmt"

// BubbleSort 冒泡排序
// 时间复杂度:
//
//	 特性: 稳定的排序, 优化后最快o(n),即对有序数组排序
//		1.未优化时: O(n²)
//			外循环n次 = n
//			内循环 n-1,n-2,n-3...1 次 = (n-1)/2
//			总: (n-1)/2 * n ≈ n²
//	 2.引入flag标记优化: o(n) 至 o(n²)
func BubbleSort(arr []int) {
	flag := 0
	for i := 0; i < len(arr); i++ {
		for j := 1; j < len(arr)-i; j++ {
			if arr[j-1] > arr[j] {
				arr[j-1], arr[j] = arr[j], arr[j-1]
				flag = 1
			}
		}
		if flag == 0 {
			break
		}
	}
}

func main() {
	arr := []int{7, 1, 4, 6, 9, 2, 5, 3}
	BubbleSort(arr)
	fmt.Println(arr)

	arr = []int{1, 2, 1, 1, 1, 1, 2}
	BubbleSort(arr)
	fmt.Println(arr)

	arr = []int{}
	BubbleSort(arr)
	fmt.Println(arr)
}
