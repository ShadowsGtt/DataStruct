package queue

type Queue struct {
	Val []interface{}
}

func (q *Queue) EnQue(val interface{}) {
	// 插入到尾部
	q.Val = append(q.Val, val)
}

func (q *Queue) DeQue() interface{} {
	// 从头部取出
	if q.Len() == 0 {
		return nil
	}
	v := q.Val[0]
	q.Val = q.Val[1:]
	return v
}

func (q *Queue) Len() int {
	return len(q.Val)
}
