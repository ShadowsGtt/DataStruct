package main

import (
	"fmt"
	"testing"
	"tree/tree"
)

func exampleTree() *tree.TreeNode {
	/*
			        1
			       / \
				  2	  3
			     / \  / \
		        4   5 6  7
	*/

	root := &tree.TreeNode{Val: 1}
	root.Left = &tree.TreeNode{Val: 2}
	root.Right = &tree.TreeNode{Val: 3}
	root.Left.Left = &tree.TreeNode{Val: 4}
	root.Left.Right = &tree.TreeNode{Val: 5}
	root.Right.Left = &tree.TreeNode{Val: 6}
	root.Right.Right = &tree.TreeNode{Val: 7}

	return root
}

func TestLevelOrderTraversal(t *testing.T) {
	root := exampleTree()
	// 广度优先遍历  输出: 1234567
	fmt.Println(LevelOrderTraversal(root))
}

func TestPreTraversal(t *testing.T) {
	root := exampleTree()
	// 深度优先遍历->先序遍历  输出: 1245367
	fmt.Println(PreTraversal(root))
}

func TestPreTraversalRecursion(t *testing.T) {
	root := exampleTree()
	// 深度优先遍历->先序遍历 递归实现  输出: 1245367
	result := []interface{}{}
	PreTraversalRecursion(root, &result)
	fmt.Println(result)
}

func TestMidTraversalRecursion(t *testing.T) {
	root := exampleTree()
	// 深度优先遍历->中序遍历 递归实现  输出: 4251637
	result := []interface{}{}
	MidTraversalRecursion(root, &result)
	fmt.Println(result)
}

func TestTailTraversalRecursion(t *testing.T) {
	root := exampleTree()
	// 深度优先遍历->后序遍历 递归实现  输出: 4526731
	result := []interface{}{}
	TailTraversalRecursion(root, &result)
	fmt.Println(result)
}
