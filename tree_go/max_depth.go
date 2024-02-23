package main

import (
	"tree/tree"
)

// TreeMaxDepth 树的最大深度
// 层次遍历
func TreeMaxDepth(root *tree.TreeNode) int {
	if root == nil {
		return 0
	}
	depth := 0
	queue := []*tree.TreeNode{}
	queue = append(queue, root)
	for len(queue) > 0 {
		depth++
		// 遍历当前层 并将下一层节点入队
		n := len(queue)
		for i := 0; i < n; i++ {
			q := queue[i]
			queue = queue[1:]
			if q.Left != nil {
				queue = append(queue, q.Left)
			}
			if q.Right != nil {
				queue = append(queue, q.Right)
			}
		}
	}
	return depth
}
