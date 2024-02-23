package main

import (
	"fmt"
)

// MaxSubArraySum 最大子序列和
func MaxSubArraySum(arr []int) int {
	if len(arr) == 0 {
		return 0
	}
	sum := 0
	maxSum := arr[0]
	for _, v := range arr {
		// 如果当前值 > 之前所有和, 刷新最大和
		sum = max(sum+v, v)
		// 比较子序列sum 和   最大sum
		maxSum = max(maxSum, sum)
	}
	return maxSum
}

func main() {
	arr := []int{-2, -1, -3, -4, -1, -2, -1, -5, -4}
	fmt.Println(MaxSubArraySum(arr))
}
