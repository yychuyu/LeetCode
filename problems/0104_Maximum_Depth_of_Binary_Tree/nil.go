package MaximumDepthofBinaryTree

import "for-an-offer/zs-leetcode-go/types"

func maxDepth(root *types.TreeNode) int {
	if root == nil {
		return 0
	}
	left := maxDepth(root.Left)+1
	right := maxDepth(root.Right)+1
	if left > right {
		return left
	}
	return right
}