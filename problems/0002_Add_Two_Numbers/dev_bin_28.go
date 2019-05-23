package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {

	num1 := []int{2, 4, 3}
	num2 := []int{5, 6, 4}
	l1 := new(ListNode)
	l2 := new(ListNode)
	cur := l1
	for key, value := range num1 {
		if key == 0 {
			cur.Val = value
		} else {
			l := new(ListNode)
			l.Val = value
			cur.Next = l
			cur = cur.Next
		}
	}
	cur = l2
	for key, value := range num2 {
		if key == 0 {
			cur.Val = value
		} else {
			l := new(ListNode)
			l.Val = value
			cur.Next = l
			cur = cur.Next
		}
	}

	result := addTwoNumbers(l1, l2)
	for result != nil {
		fmt.Println(result.Val)
		result = result.Next
	}

}

// addTwoNumbers ...
func addTwoNumbers(l1, l2 *ListNode) *ListNode {
	result := new(ListNode)
	cur := result
	p, q := l1, l2
	isUpper := false
	for p != nil || q != nil || isUpper {
		sum := 0
		if isUpper {
			sum += 1
		}
		if p != nil {
			sum += p.Val
			p = p.Next
		}
		if q != nil {
			sum += q.Val
			q = q.Next
		}
		cur.Next = new(ListNode)
		cur = cur.Next
		cur.Val = sum % 10
		if sum > 9 {
			isUpper = true
		} else {
			isUpper = false
		}
	}
	return result.Next
}
