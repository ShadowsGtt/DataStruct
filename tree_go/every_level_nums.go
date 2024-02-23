package main

import "tree/tree"

// EveryLevelNums 二叉树每一层节点个数
func EveryLevelNums(root *tree.TreeNode) []int {
	queue := []interface{}{}
	queue = append(queue, root)

	levelNums := []int{}

	for len(queue) > 0 {
		n := len(queue)
		// 将当前层的下一层加入到队列
		for i := 0; i < n; i++ {
			node := queue[i].(*tree.TreeNode)
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		levelNums = append(levelNums, n)
		queue = queue[n:] // 将当前层全部移除
	}
	return levelNums
}
