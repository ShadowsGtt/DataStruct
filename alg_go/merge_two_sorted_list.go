package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func MergeSortedList(l1 *ListNode, l2 *ListNode) *ListNode {
	list := &ListNode{}
	head := list
	for l1 != nil && l2 != nil {
		if l1.Val > l2.Val {
			list.Next = l2
			l2 = l2.Next
		} else {
			list.Next = l1
			l1 = l1.Next
		}
		list = list.Next
	}
	if l1 != nil {
		list.Next = l1
	}
	if l2 != nil {
		list.Next = l2
	}
	return head
}
func main() {
	l1 := &ListNode{
		Val: 2,
		Next: &ListNode{
			Val: 5,
			Next: &ListNode{
				Val: 7,
				Next: &ListNode{
					Val: 9,
					Next: &ListNode{
						Val: 10,
					},
				},
			},
		},
	}
	l2 := &ListNode{
		Val: 1,
		Next: &ListNode{
			Val: 6,
			Next: &ListNode{
				Val: 11,
			},
		},
	}
	p := MergeSortedList(l1, l2)
	for p != nil {
		fmt.Printf("%d ", p.Val)
		p = p.Next
	}

}