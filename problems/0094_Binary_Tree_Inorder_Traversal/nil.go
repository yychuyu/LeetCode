package BinaryTreeInorderTraversal

import "for-an-offer/zs-leetcode-go/types"

func inorderTraversal(root *types.TreeNode) []int {
	travel := make([]int, 0)
	stack := make([]*types.TreeNode, 0)
	if root == nil {
		return []int{}
	}
	p := root
	for p != nil || len(stack) > 0 {
		for p != nil {
			stack = append(stack, p)
			p = p.Left
		}
		if len(stack) > 0 {
			tmp := stack[len(stack)-1]
			travel = append(travel, tmp.Val)
			p = tmp.Right
			stack = stack[:len(stack)-1]
		}
	}
	return travel
}