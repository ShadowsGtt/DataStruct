package main

import (
	"fmt"
)

func partition(nums []int, left, right int) int {
	mid := (left + right) / 2
	// 获取中位数作为基准数 优化快排
	medianIdx := getMedian(nums, left, mid, right)
	// 将基准数移动到最左边
	nums[left], nums[medianIdx] = nums[medianIdx], nums[left]
	i, j := left, right
	// 升序排序
	for i < j {
		// 从左往右  找到一个比基准大的
		for i < j && nums[i] < nums[left] {
			i++
		}

		// 从右往左   找到一个比基准小的
		for i < j && nums[j] > nums[left] {
			j--
		}

		// 交换
		nums[i], nums[j] = nums[j], nums[i]
	}

	// 将基准数移到对应位置
	nums[left], nums[i] = nums[i], nums[left]
	return i
}

// getMedian 中位数
func getMedian(nums []int, i, j, k int) int {
	// i 是不是中位数, 两个必然有一个为true
	// 最终肯定是:
	//   nums[i] < nums[j] && nums[i] > nums[k]
	//   or
	//   nums[i] > nums[j] && nums[i] < nums[k]
	//   不管哪一种情况, nums[i]都是中位数
	if (nums[i] < nums[j]) != (nums[i] < nums[k]) {
		return i
	} else if (nums[j] < nums[k]) != (nums[j] < nums[i]) {
		return j
	}

	return k
}

func FindTopK(nums []int, k int) int {
	left := 0
	right := len(nums) - 1

	idx := 0
	curK := -1
	for curK != k {
		// 获取中位数下标
		idx = partition(nums, left, right)
		//	fmt.Println(fmt.Sprintf("基准: %d, 分隔后: %v", nums[idx], nums))
		curK = len(nums) - idx
		//	fmt.Println("当前K: ", curK)
		if curK > k {
			left = idx + 1
		}
		if curK < k {
			right = idx
		}
	}

	return idx
}

func main() {

	// 1 2 4 5 6 7 9
	nums := []int{5, 2, 7, 4, 9, 6, 1}
	k := 3
	kIdx := FindTopK(nums, k)

	fmt.Println(fmt.Sprintf("第%d大的数字为: %d", k, nums[kIdx]))
	fmt.Println(nums)
}
