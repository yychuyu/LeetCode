package ValidateBinarySearchTree

import (
	"for-an-offer/zs-leetcode-go/types"
)

func preOrder(root *types.TreeNode, res *[]int) {
	if root.Left != nil {
		preOrder(root.Left, res)
	}
	*res = append(*res, root.Val)
	if root.Right != nil {
		preOrder(root.Right, res)
	}
}

func isValidBST(root *types.TreeNode) bool {
	if root == nil {
		return false
	}
	res := make([]int, 0)
	preOrder(root, &res)
	for i := 1; i < len(res); i++ {
		if res[i] <= res[i-1] {
			return false
		}
	}
	return true
}
