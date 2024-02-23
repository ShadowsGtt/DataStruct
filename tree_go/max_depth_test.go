package main

import (
	"fmt"
	"testing"
	"tree/tree"
)

func TestTreeMaxDepth(t *testing.T) {
	/*
			        1
			       / \
				  2	  4
			     /
		        3
	*/
	root := &tree.TreeNode{Val: 1}
	root.Left = &tree.TreeNode{Val: 2}
	root.Left.Left = &tree.TreeNode{Val: 3}

	root.Right = &tree.TreeNode{Val: 4}
	//root.Right.Right = &tree.TreeNode{Val: 5}
	fmt.Println(TreeMaxDepth(root))
}
