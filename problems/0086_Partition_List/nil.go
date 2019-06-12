package PartitionList

import (
	"for-an-offer/zs-leetcode-go/types"
)

func partition(head *types.ListNode, x int) *types.ListNode {
	if head == nil {
		return nil
	}
	var flagNode *types.ListNode
	var pre *types.ListNode
	walk, preWalk := head, head
	for walk != nil {
		if walk.Val >= x {
			if flagNode == nil {
				flagNode = walk
				pre = preWalk
			}
			preWalk = walk
			walk = walk.Next
		} else {
			if flagNode != nil {
				preWalk.Next = walk.Next
				walk.Next = flagNode
				if pre == flagNode {
					head = walk
					pre = head
				} else {
					pre.Next = walk
					pre = pre.Next
				}
				walk = preWalk.Next
			} else {
				preWalk = walk
				walk = walk.Next
			}

		}
	}
	return head
}
