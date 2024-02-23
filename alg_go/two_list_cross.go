package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

// GetListCross 获取链表的交叉点
// 思路: p1, p2双指针遍历两个链表，直到 p1 == p2 (没有交点的话, p1==p2==nil)
//
//	当p1到l1尾部时，p1转到l2头部
//	当p2走到l2尾部时，p2转到l1头部
//
// 原因: (a是链表l1的长度，b是链表l2长度，c是公共部分长度 )
//
//	指针p1走过的距离为: a + (b - c)
//	指针p2走过的距离为: b + (a - c)
//	可以看出 p1和p2走过的距离相等
func GetListCross(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil || l2 == nil {
		return nil
	}
	p1c := 0
	p2c := 0

	p1 := l1
	p2 := l2
	for p1 != p2 {
		if p1 == nil {
			p1 = l2
		} else {
			p1 = p1.Next
			p1c++
		}
		if p2 == nil {
			p2 = l1
		} else {
			p2 = p2.Next
			p2c++
		}
	}
	fmt.Println(p1c, p2c)

	return p1
}

func main() {
	c := &ListNode{Val: 8}
	c.Next = &ListNode{Val: 9}
	c.Next.Next = &ListNode{Val: 10}

	p1 := &ListNode{Val: 1}
	p1.Next = &ListNode{Val: 2}
	p1.Next.Next = &ListNode{Val: 3}

	p2 := &ListNode{Val: 4}
	p2.Next = &ListNode{Val: 5}

	p1.Next.Next.Next = c
	p2.Next.Next = c

	fmt.Println(GetListCross(p1, p2))

}
