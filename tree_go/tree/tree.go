package tree

type TreeNode struct {
	Val   interface{}
	Left  *TreeNode
	Right *TreeNode
}

type TreeNodeNumber struct {
	Val   int
	Left  *TreeNodeNumber
	Right *TreeNodeNumber
}
