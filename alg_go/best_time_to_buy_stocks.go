package main

import "fmt"

// BestTimeToBuyStocks 买股票的最佳时机
// leetcode 原题链接：买股票的最佳时机
// 难度级别：简单
// 题目： 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。 注意：你不能在买入股票前卖出股票。
// 示例1：
// 输入: [7,1,5,3,6,4] 输出: 5 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
// 示例2:
// 输入: [7,6,4,3,1] 输出: 0 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
func BestTimeToBuyStocks(arr []int) int {
	if len(arr) == 0 {
		return 0
	}
	profit := 0
	floor := arr[0] // 买入的最低点
	for i := 1; i < len(arr); i++ {
		if arr[i] < floor {
			floor = arr[i]
		}
		// 计算收益是否最大
		if arr[i]-floor > profit {
			profit = arr[i] - floor
		}
	}
	return profit
}

func main() {
	fmt.Println(BestTimeToBuyStocks([]int{7, 1, 5, 3, 6, 4}))

}
