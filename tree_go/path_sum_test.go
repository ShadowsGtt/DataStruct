package main

import (
	"fmt"
	"testing"
	"tree/tree"
)

func TestPathSum(t *testing.T) {
	//              5
	//             / \
	//            4   8
	//           /   / \
	//          11  13  4
	//         /  \    / \
	//        7    2  5   1
	root := &tree.TreeNodeNumber{Val: 5}
	root.Left = &tree.TreeNodeNumber{Val: 4}
	root.Left.Left = &tree.TreeNodeNumber{Val: 11}
	root.Left.Left.Left = &tree.TreeNodeNumber{Val: 7}
	root.Left.Left.Right = &tree.TreeNodeNumber{Val: 2}

	root.Right = &tree.TreeNodeNumber{Val: 8}
	root.Right.Left = &tree.TreeNodeNumber{Val: 13}
	root.Right.Right = &tree.TreeNodeNumber{Val: 4}
	root.Right.Right.Left = &tree.TreeNodeNumber{Val: 5}
	root.Right.Right.Right = &tree.TreeNodeNumber{Val: 1}

	PathSum(root, []int{}, 22)
	fmt.Println(TotalList)

}
