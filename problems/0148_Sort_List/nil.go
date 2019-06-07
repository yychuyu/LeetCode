package SortList

import "for-an-offer/zs-leetcode-go/types"

func sortAux(start, end *types.ListNode) {
	if start == end || start.Next == end {
		return
	}
	node := start
	maxFlag, walk := start, start.Next
	for walk != nil {
		if walk.Val < node.Val {
			maxFlag = maxFlag.Next
			maxFlag.Val, walk.Val = walk.Val, maxFlag.Val
		}
		walk = walk.Next
	}
	node.Val, maxFlag.Val = maxFlag.Val, node.Val
	sortAux(start, maxFlag)
	sortAux(maxFlag.Next, end)
}
func sortList(head *types.ListNode) *types.ListNode {
	if head == nil {
		return nil
	}
	sortAux(head, nil)
	return head
}
