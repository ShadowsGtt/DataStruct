package main

import "fmt"

// FindSortedNumRange 在有序数组中查找目标值的范围
// 例如: 3 6 7 7 7 8 9
// 查找: 7
// 范围: 2,4 (下标2到4)
func FindSortedNumRange(nums []int, target int) (int, int) {
	left := 0
	right := len(nums) - 1
	rl := -1
	rr := -1
	// 寻找左边界
	for left <= right {
		mid := (right + left) / 2
		if nums[mid] > target || (nums[mid] == target) {
			right = mid - 1
			rl = mid
		} else {
			left = mid + 1
		}
	}
	// 寻找右边界
	left = 0
	right = len(nums) - 1
	for left <= right {
		mid := (right + left) / 2
		if nums[mid] < target || (nums[mid] == target) {
			left = mid + 1
			rr = mid
		} else {
			right = mid - 1
		}
	}

	return rl, rr
}

func main() {
	nums := []int{3, 6, 7, 7, 7, 7, 8, 9}
	fmt.Println(FindSortedNumRange(nums, 7))
}
