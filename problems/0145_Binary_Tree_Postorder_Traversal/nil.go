package BinaryTreePostorderTraversal

import (
	"for-an-offer/zs-leetcode-go/types"
)

func postorderTraversal(root *types.TreeNode) []int {
	result := make([]int, 0)
	if root == nil {
		return result
	}
	stack := make([]*types.TreeNode, 0)
	current := root
	for current != nil || len(stack) != 0 {
		for current != nil {
			stack = append(stack, current)
			stack = append(stack, current)
			current = current.Left
		}
		current = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if len(stack) != 0 && current == stack[len(stack)-1] {
			if current != nil {
				current = current.Right
			} else {
				current = nil
			}
		} else {
			result = append(result, current.Val)
			current = nil
		}
	}
	return result
}