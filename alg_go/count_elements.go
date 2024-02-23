package main

import "fmt"

// 一个长度大小为N的数组，数组中的每个元素的取值范围在[1，N]，且为正整数。
// 问：如何在时间复杂度为O(N)，空间复杂度为O(1)的条件下，统计数组中不同元素出现的次数。
// 思路: 数组元素的取值是[1,N],所以可以将 数组下标当做数字，对应下标里的数据存储该数字出现次数
//
//	因为数组元素都是正整数,所以计数使用负数来计，这样可以判断当前位置是否已经被计数过
func countElements(nums []int) {
	// 0  1  2  3  4
	// 2  5  5  2  3
	// 5  -1 5  2  3
	// 下标从0开始遍历
	for i := 0; i < len(nums); {
		numIdx := nums[i] - 1 // 当前值-1做下标(需要-1，是因为数字范围是[1-N])
		// 处理当前位置, 直到当前位置的值 <= 0 (注意numIdx是当前位置值-1)
		if numIdx < 0 {
			i++
			continue
		}
		// 当前下标对应的值 >= 0

		// 如果目标数已经计数, 则计数+1, 并将当前值标记为0
		if nums[numIdx] <= 0 {
			nums[numIdx] -= 1
			nums[i] = 0 // 目标位置已经计数过了, 无需将目标位置的数值存储到当前位置, 当前位置归0, 便于下次循环判断当前位置是否完成
		}
		// 如果目标数未计数, 则将目标数存储到当前位置, 并对目标数计数
		if nums[numIdx] > 0 {
			nums[i] = nums[numIdx] // 目标位置的数字存储到当前位置
			nums[numIdx] = -1      // 目标数计数
		}
		fmt.Println("数组变化: ", nums)
	}
}

func main() {
	nums := []int{3, 1, 4, 1, 5, 9, 2, 6, 5, 3}
	fmt.Println("原数组: ", nums)
	countElements(nums)
	fmt.Println("计数后: ", nums)
	for i := 0; i < len(nums); i++ {
		fmt.Println(fmt.Sprintf("%d出现%d次", i+1, -nums[i]))
	}
}
