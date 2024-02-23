package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func widthOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}

	res := 0
	queue := []*Node{{root, 1}}

	for len(queue) > 0 {
		left := queue[0].val
		right := left
		n := len(queue)

		for i := 0; i < n; i++ {
			node := queue[i].node
			v := queue[i].val
			right = v
			if node.Left != nil {
				queue = append(queue, &Node{node.Left, v * 2})
			}
			if node.Right != nil {
				queue = append(queue, &Node{node.Right, v*2 + 1})
			}
		}

		queue = queue[n:]
		res = max(res, right-left+1)
	}

	return res
}

type Node struct {
	node *TreeNode
	val  int
}

//          1
//         / \
//        3   2
//       /     \
//      5       9
//     /         \
//    6           7

func main() {
	tree := &TreeNode{Val: 1}
	tree.Left = &TreeNode{Val: 3}
	tree.Left.Left = &TreeNode{Val: 5}
	tree.Left.Left.Left = &TreeNode{Val: 6}

	tree.Right = &TreeNode{Val: 2}
	tree.Right.Right = &TreeNode{Val: 9}
	tree.Right.Right.Right = &TreeNode{Val: 7}
	fmt.Println(widthOfBinaryTree(tree))

	tree2 := &TreeNode{Val: 1}
	tree2.Left = &TreeNode{Val: 3}
	tree2.Left.Left = &TreeNode{Val: 5}

	tree2.Right = &TreeNode{Val: 2}

	fmt.Println(widthOfBinaryTree(tree2))

}
