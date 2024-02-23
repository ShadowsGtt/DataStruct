package stack

import (
	"fmt"
	"testing"
)

func TestStack(t *testing.T) {
	stack := &Stack{}
	stack.Push(1)
	stack.Push(2)
	stack.Push(3)

	fmt.Println(stack.Pop())
	fmt.Println(stack.Pop())
	fmt.Println(stack.Pop())
	fmt.Println(stack.Pop())

}
