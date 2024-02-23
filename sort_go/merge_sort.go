package main

import "fmt"

func MergerSort() {

}

func Merge(nums []int, left, mid, right int) {
	i := mid - 1 // 数组1末尾
	j := right   // 数组2末尾
	k := right   // 新数组末尾下标

	for i >= left && j >= mid {
		fmt.Println(nums[i], nums[j])
		if nums[i] > nums[j] {
			nums[k] = nums[i]
			k--
			i--
		} else {
			nums[k] = nums[j]
			k--
			j--
		}
	}
	for i >= left {
		nums[k] = nums[i]
		k--
		i--
	}
	for j >= mid {
		nums[k] = nums[j]
		k--
		j--
	}
}

func main() {
	nums := []int{4, 6, 1, 5}
	mid := len(nums) / 2
	Merge(nums, 0, mid, len(nums)-1)
	fmt.Println(nums)
}
