package main

import (
	"container/list"
	"fmt"
)

func Sum(l1, l2 *list.List) *list.List {
	if l1 == nil || l2 == nil {
		return nil
	}
	flag := 0
	ret := list.New()
	for {

		n1 := 0
		n2 := 0
		e1 := l1.Front()
		e2 := l2.Front()
		if e1 == nil && e2 == nil {
			break
		}

		if e1 != nil {
			n1 = e1.Value.(int)
			l1.Remove(e1)
		}
		if e2 != nil {
			n2 = e2.Value.(int)
			l2.Remove(e2)
		}

		curSum := n1 + n2 + flag
		n := curSum % 10
		if curSum >= 10 {
			flag = 1
		} else {
			flag = 0
		}
		ret.PushBack(n)

	}
	if flag == 1 {
		ret.PushBack(1)
	}
	return ret
}

func main() {
	// 243 564
	l1 := list.New()
	l1.PushBack(2)
	l1.PushBack(4)
	//l1.PushBack(3)
	PrintList(l1)
	fmt.Println()

	l2 := list.New()
	l2.PushBack(5)
	l2.PushBack(6)
	l2.PushBack(4)
	PrintList(l2)
	fmt.Println()

	l3 := Sum(l1, l2)
	PrintList(l3)
	fmt.Println()

}

func PrintList(l *list.List) {
	node := l.Front()

	for {
		if node == nil {
			break
		}
		fmt.Printf("%v ", node.Value)
		node = node.Next()
	}
}
