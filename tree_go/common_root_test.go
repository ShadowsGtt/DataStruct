package main

import (
	"fmt"
	"testing"
	"tree/tree"
)

func TestGetCommonRoot(t *testing.T) {
	/*
		          6
		        /   \
		       7       4
		     /   \     /
		    1     3   8
		     \    /
			  2  5

	*/
	root := &tree.TreeNode{Val: 6}
	root.Left = &tree.TreeNode{Val: 7}
	root.Left.Left = &tree.TreeNode{Val: 1}
	root.Left.Left.Right = &tree.TreeNode{Val: 2}

	root.Left.Right = &tree.TreeNode{Val: 3}
	root.Left.Right.Left = &tree.TreeNode{Val: 5}

	root.Right = &tree.TreeNode{Val: 4}
	root.Right.Left = &tree.TreeNode{Val: 8}

	p := root.Left
	q := root.Left.Left

	fmt.Println("公共祖先: ", GetCommonRoot(root, p, q))
}
