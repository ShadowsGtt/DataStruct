package main

import "tree/tree"

// SnakePrint 蛇形打印树, 从上之下: 从左右到,从右到左
func SnakePrint(root *tree.TreeNode) [][]interface{} {
	queue := []interface{}{}
	queue = append(queue, root)

	snakeOut := [][]interface{}{}

	levelOut := []interface{}{}
	reversePrint := false
	for len(queue) > 0 {
		n := len(queue)
		// 将当前层的下一层加入到队列
		for i := 0; i < n; i++ {
			node := queue[i].(*tree.TreeNode)
			if !reversePrint {
				levelOut = append(levelOut, node.Val)
			} else {
				levelOut = append([]interface{}{node.Val}, levelOut...)
			}
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		reversePrint = !reversePrint
		snakeOut = append(snakeOut, levelOut)
		levelOut = []interface{}{}
		queue = queue[n:] // 将当前层全部移除
	}
	return snakeOut
}
