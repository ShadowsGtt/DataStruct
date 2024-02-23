package main

import (
	"fmt"
	"strings"
)

type LRUCache struct {
	keyNode map[string]*ListNode // key -> list node
	dll     *DoubleLinkList      // 双向链表
	cap     int32
	len     int32
}

func NewLRUCache(cap int32) *LRUCache {
	return &LRUCache{
		keyNode: map[string]*ListNode{},
		dll:     &DoubleLinkList{},
		cap:     cap,
	}
}

func (lru *LRUCache) String() string {
	return lru.dll.String()
}

func (lru *LRUCache) Use(key string, data interface{}) {
	node, ok := lru.keyNode[key]
	// key 存在则删除再插入到尾部
	if ok {
		lru.dll.Delete(node)
		lru.dll.InsertTailNode(node)
		return
	}
	// key 不存在
	node = &ListNode{Data: data}
	// 空间满 先删除最少使用
	if lru.len >= lru.cap {
		lru.dll.Delete(lru.dll.Head)
		delete(lru.keyNode, key)
		lru.len--
	}
	// 新增
	lru.len++
	lru.keyNode[key] = node
	lru.dll.InsertTailNode(node)
}

// ListNode 链表节点
type ListNode struct {
	Key   string
	Data  interface{} // 数据
	Front *ListNode   // 前置节点
	Rear  *ListNode   // 后置节点
}

// DoubleLinkList 双向链表
type DoubleLinkList struct {
	Head *ListNode // 头部节点
	Tail *ListNode // 尾部节点
}

func (dl *DoubleLinkList) String() string {
	o := []string{}
	for x := dl.Head; x != nil; {
		o = append(o, fmt.Sprintf("%v", x.Data))
		x = x.Rear
	}

	return strings.Join(o, " - ")
}

// InsertHeadNode 头部插入
func (dl *DoubleLinkList) InsertHeadNode(node *ListNode) {
	node.Rear = nil
	node.Front = nil
	// 首次插入
	if dl.Head == nil {
		dl.Head = node
		dl.Tail = node
		return
	}
	// 非首次插入
	node.Rear = dl.Head
	dl.Head.Front = node
	dl.Head = node
}

// InsertHead 头部插入
func (dl *DoubleLinkList) InsertHead(data interface{}) {
	node := &ListNode{
		Rear:  nil,
		Front: nil,
		Data:  data,
	}
	// 首次插入
	if dl.Head == nil {
		dl.Head = node
		dl.Tail = node
		return
	}
	// 非首次插入
	node.Rear = dl.Head
	dl.Head.Front = node
	dl.Head = node
}

// InsertTail 尾部插入
func (dl *DoubleLinkList) InsertTail(data interface{}) {
	node := &ListNode{
		Rear:  nil,
		Front: nil,
		Data:  data,
	}
	// 首次插入
	if dl.Tail == nil {
		dl.Head = node
		dl.Tail = node
		return
	}
	dl.Tail.Rear = node
	node.Front = dl.Tail
	dl.Tail = node
}

// InsertTailNode 尾部插入
func (dl *DoubleLinkList) InsertTailNode(node *ListNode) {
	node.Rear = nil
	node.Front = nil
	// 首次插入
	if dl.Tail == nil {
		dl.Head = node
		dl.Tail = node
		return
	}
	dl.Tail.Rear = node
	node.Front = dl.Tail
	dl.Tail = node
}

// Delete 删除
func (dl *DoubleLinkList) Delete(node *ListNode) {
	if node == nil {
		return
	}
	// 链表只有一个节点情况
	if dl.Head == dl.Tail && dl.Head == node {
		dl.Head = nil
		dl.Tail = nil
		return
	}
	// 自己是tail
	if dl.Tail == node {
		dl.Tail = dl.Tail.Front
		node.Front.Rear = nil
		node.Front = nil
		return
	}
	// 自己是head
	if dl.Head == node {
		dl.Head = node.Rear
		node.Rear.Front = nil
		node.Rear = nil
		return
	}
	// 中间节点
	node.Front.Rear = node.Rear
	node.Rear.Front = node.Front
	node.Front = nil
	node.Rear = nil
}

func main() {
	lru := NewLRUCache(4)
	lru.Use("1", 1)
	lru.Use("2", 2)
	lru.Use("3", 3)
	lru.Use("4", 4)
	lru.Use("5", 5)
	lru.Use("5", 5)
	lru.Use("4", 4)

	fmt.Println(lru.String())

	return
	list := &DoubleLinkList{}

	n1 := &ListNode{Data: 1}
	list.InsertHeadNode(n1)
	fmt.Println(list.String())

	n2 := &ListNode{Data: 2}
	list.InsertHeadNode(n2)
	fmt.Println(list.String())

	n3 := &ListNode{Data: 3}
	list.InsertHeadNode(n3)
	fmt.Println(list.String())

	n4 := &ListNode{Data: 4}
	list.InsertTailNode(n4)
	fmt.Println(list.String())

	n5 := &ListNode{Data: 5}
	list.InsertTailNode(n5)
	fmt.Println(list.String())

	n6 := &ListNode{Data: 6}
	list.InsertTailNode(n6)
	fmt.Println(list.String())

	list.Delete(n1)
	fmt.Println(list.String())
}
