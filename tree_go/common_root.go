package main

import (
	"fmt"
	"tree/tree"
)

// GetCommonRoot 获取公共祖先
func GetCommonRoot(root *tree.TreeNode, p, q *tree.TreeNode) *tree.TreeNode {
	if root != nil {
		fmt.Println("当前节点: ", root.Val)
	} else {
		fmt.Println("当前节点: ", nil)
	}
	if root == nil || root == p || root == q {
		return root
	}
	left := GetCommonRoot(root.Left, p, q)
	right := GetCommonRoot(root.Right, p, q)
	fmt.Println("【递归回来】:", left, right)
	if left == nil && right == nil {
		fmt.Println("===左右都为: ", nil)
		return nil
	}
	if left == nil {
		fmt.Println("left 为nil, right: ", right.Val)
		return right
	}
	if right == nil {
		fmt.Println("right 为nil, left: ", left.Val)
		return left
	}
	fmt.Println("返回root:  ", root)

	return root
}
