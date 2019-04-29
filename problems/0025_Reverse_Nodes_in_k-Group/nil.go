package ReverseNodesinkGroup

import (
	"for-an-offer/zs-leetcode-go/types"
)

//  隔k个节点进行交换
func reverseKGroup(head *types.ListNode, k int) *types.ListNode {
	if head == nil {
		return nil
	}
	if k <= 1 {
		return head
	}
	p := head
	sum := 0
	for p != nil {
		sum += 1
		p = p.Next
	}
	if sum < k {
		return head
	}
	index := 0
	start, end := head, head
	var pHead *types.ListNode
	var preNode *types.ListNode
	for end != nil {
		index ++
		end = end.Next
		if index == k {
			tmpHead, tmpEnd := reverse(start, end)
			if pHead == nil {
				pHead = tmpHead
			}
			if preNode != nil {
				preNode.Next = tmpHead
			}
			preNode = tmpEnd
			index = 0
			start = end
		}
	}
	return pHead
}

func reverse(head *types.ListNode, endNode *types.ListNode) (*types.ListNode, *types.ListNode){
	p, q := head, head.Next
	p.Next = endNode
	for q != endNode {
		node := q.Next
		q.Next = p
		p = q
		q = node
	}
	return p, head
}