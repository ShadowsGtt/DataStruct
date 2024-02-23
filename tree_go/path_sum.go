package main

import (
	"tree/tree"
)

var TotalList [][]int

func PathSum(root *tree.TreeNodeNumber, pathList []int, sum int) {
	if root == nil {
		return
	}
	pathList = append(pathList, root.Val)
	// 当前节点没有子节点 and 当前节点值等于sum
	if root.Left == nil && root.Right == nil && sum == root.Val {
		TotalList = append(TotalList, append([]int{}, pathList...))
		return
	}
	// 递归左子树
	if root.Left != nil {
		PathSum(root.Left, pathList, sum-root.Val)
	}
	// 递归右子树
	if root.Right != nil {
		PathSum(root.Right, pathList, sum-root.Val)
	}

}
