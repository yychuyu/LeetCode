package BinaryTreeMaximumPathSum

import (
	"for-an-offer/zs-leetcode-go/types"
)

func _max(nums ...int) int{
	maxNum := nums[0]
	for _, item := range nums[1:] {
		if item > maxNum {
			maxNum = item
		}
	}
	return maxNum
}

// aux返回的是当前节点的最大值呀, 只能要一条线，去掉另一面
func aux(root *types.TreeNode, max *int) int{
	left, right, tmp := 0, 0, 0
	if root.Left != nil {
		left = aux(root.Left, max)
	}
	if left != 0 && left > *max {
		*max = left
	}
	tmp = _max(root.Val, root.Val+left)
	if tmp > *max {
		*max = tmp
	}
	if root.Right != nil {
		right = aux(root.Right, max)
	}
	if right != 0 && right > *max {
		*max = right
	}
	tmp = _max(tmp, tmp+right)
	if tmp > *max {
		*max = tmp
	}
	root.Val = _max(root.Val, root.Val+left, root.Val+right)
	return root.Val
}

func maxPathSum(root *types.TreeNode) int {
	if root.Left == nil && root.Right == nil {
		return root.Val
	}
	max := root.Val
	aux(root, &max)
	return max
}
