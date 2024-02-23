package stack

type Stack struct {
	stack []interface{}
}

func (s *Stack) Push(v interface{}) {
	s.stack = append(s.stack, v)
}

func (s *Stack) Pop() interface{} {
	l := s.Len()
	if l == 0 {
		return nil
	}
	v := s.stack[l-1]
	s.stack = s.stack[0 : l-1]
	return v
}

func (s *Stack) Len() int {
	return len(s.stack)
}
