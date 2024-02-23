package main

import (
	"tree/queue"
	"tree/stack"
	"tree/tree"
)

// LevelOrderTraversal 层序遍历
// 又叫: 广度优先遍历 breadth-first traversal
// 思想: 从上到下 - 从左到右   依次遍历。需要借助队列实现
func LevelOrderTraversal(root *tree.TreeNode) []interface{} {
	if root == nil {
		return nil
	}
	valList := []interface{}{}
	q := &queue.Queue{}
	q.EnQue(root)
	for q.Len() > 0 {
		v := q.DeQue().(*tree.TreeNode)
		valList = append(valList, v.Val)
		if v.Left != nil {
			q.EnQue(v.Left)
		}
		if v.Right != nil {
			q.EnQue(v.Right)
		}
	}

	return valList
}

// PreTraversalRecursion 先序遍历 - 根左右
// 递归实现
func PreTraversalRecursion(root *tree.TreeNode, result *[]interface{}) {
	if root == nil {
		return
	}
	*result = append(*result, root.Val)
	PreTraversalRecursion(root.Left, result)
	PreTraversalRecursion(root.Right, result)
}

// MidTraversalRecursion 中序遍历 - 左根右
// 递归实现
func MidTraversalRecursion(root *tree.TreeNode, result *[]interface{}) {
	if root == nil {
		return
	}
	MidTraversalRecursion(root.Left, result)
	*result = append(*result, root.Val)
	MidTraversalRecursion(root.Right, result)
}

// TailTraversalRecursion 后序遍历 - 左右根
// 递归实现
func TailTraversalRecursion(root *tree.TreeNode, result *[]interface{}) {
	if root == nil {
		return
	}
	TailTraversalRecursion(root.Left, result)
	TailTraversalRecursion(root.Right, result)
	*result = append(*result, root.Val)
}

// PreTraversal 先序遍历 - 根左右
// 利用栈的方式实现
func PreTraversal(root *tree.TreeNode) []interface{} {
	if root == nil {
		return nil
	}
	st := &stack.Stack{}
	st.Push(root)

	result := []interface{}{}

	for st.Len() != 0 {
		node := st.Pop().(*tree.TreeNode)
		result = append(result, node.Val)

		if node.Right != nil {
			st.Push(node.Right)
		}
		if node.Left != nil {
			st.Push(node.Left)
		}
	}

	return result
}
