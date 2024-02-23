package main

import "tree/tree"

type Node struct {
	Node  *tree.TreeNode
	Index int
}

// TreeMaxWidth 数的最大宽度
func TreeMaxWidth(root *tree.TreeNode) int {
	queue := []*Node{}
	queue = append(queue, &Node{Node: root, Index: 1})
	maxWidth := 0
	for len(queue) > 0 {
		n := len(queue)
		left := queue[0]
		right := left
		// 遍历当前层 & 将该层节点的下一层节点全部加入队列
		for i := 0; i < n; i++ {
			node := queue[i]
			right = node
			if node.Node.Left != nil {
				queue = append(queue, &Node{Node: node.Node.Left, Index: node.Index * 2})
			}
			if node.Node.Right != nil {
				queue = append(queue, &Node{Node: node.Node.Right, Index: node.Index*2 + 1})
			}
		}
		// 移除当前层
		queue = queue[n:]
		maxWidth = max(maxWidth, right.Index-left.Index+1)
	}

	return maxWidth
}
