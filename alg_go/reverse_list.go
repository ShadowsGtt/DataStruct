package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

// ReverseList 反转链表
func ReverseList(head *ListNode) *ListNode {
	var (
		pre  *ListNode
		cur  = head
		next *ListNode
	)
	for cur != nil {
		next = cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}

	return pre
}

func PrintList(head *ListNode) {
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}

	fmt.Println()
}

func main() {
	list := &ListNode{Val: 1}
	list.Next = &ListNode{Val: 2}
	list.Next = &ListNode{Val: 3}
	list.Next.Next = &ListNode{Val: 4}
	list.Next.Next.Next = &ListNode{Val: 5}

	PrintList(list)

	ll := ReverseList(list)
	PrintList(ll)
}
