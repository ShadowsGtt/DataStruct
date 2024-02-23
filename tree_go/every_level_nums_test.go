package main

import (
	"fmt"
	"testing"
	"tree/tree"
)

func TestEveryLevelNums(t *testing.T) {
	//              5
	//             / \
	//            4   8
	//           /   / \
	//          11  13  4
	//         /  \    / \
	//        7    2  5   1
	root := &tree.TreeNode{Val: 5}
	root.Left = &tree.TreeNode{Val: 4}
	root.Left.Left = &tree.TreeNode{Val: 11}
	root.Left.Left.Left = &tree.TreeNode{Val: 7}
	root.Left.Left.Right = &tree.TreeNode{Val: 2}

	root.Right = &tree.TreeNode{Val: 8}
	root.Right.Left = &tree.TreeNode{Val: 13}
	root.Right.Right = &tree.TreeNode{Val: 4}
	root.Right.Right.Left = &tree.TreeNode{Val: 5}
	root.Right.Right.Right = &tree.TreeNode{Val: 1}

	n := EveryLevelNums(root)
	fmt.Println(n)
}
