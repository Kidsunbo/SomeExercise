package main

import (
	"fmt"
	"strconv"
	"strings"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	op := head
	for op.Next != nil {
		if op.Val == op.Next.Val {
			op.Next = op.Next.Next
			continue
		}
		op = op.Next
	}
	return head
}

func createList(param ...int) *ListNode {
	if len(param) == 0 {
		return nil
	}
	head := &ListNode{Val: param[0]}
	result := head
	for _, item := range param[1:] {
		head.Next = &ListNode{Val: item}
		head = head.Next
	}
	return result
}

func printList(l *ListNode) string {
	sb := strings.Builder{}
	if l == nil {
		return "null"
	}
	sb.WriteString(strconv.FormatInt(int64(l.Val), 10))
	l = l.Next
	for l != nil {
		sb.WriteString("->")
		sb.WriteString(strconv.FormatInt(int64(l.Val), 10))
		l = l.Next
	}
	return sb.String()
}

func main() {
	l := createList(1, 2, 3, 3, 3, 3, 4, 5, 5, 8)
	fmt.Println(printList(l))
	r := deleteDuplicates(l)
	fmt.Println(printList(r))

	l = createList()
	fmt.Println(printList(l))
	r = deleteDuplicates(l)
	fmt.Println(printList(r))

}
