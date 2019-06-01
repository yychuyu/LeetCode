package PathSumII

import (
	"for-an-offer/zs-leetcode-go/types"
)


func absCompare(a, b int) bool {
	return a != b
}

func pathAux(root *types.TreeNode, now, target int, stack []int, res *[][]int) {
	now += root.Val
	stack = append(stack, root.Val)
	flag := root.Left == nil && root.Right == nil
	if flag && now == target {
		tmp := make([]int, len(stack))
		copy(tmp, stack)
		*res = append(*res, tmp)
	}
	if root.Left != nil  {
		pathAux(root.Left, now, target, stack, res)
	}
	if root.Right != nil{
		pathAux(root.Right, now, target, stack, res)
	}
	now -= root.Val
	stack = stack[:len(stack)-1]
}

func pathSum(root *types.TreeNode, sum int) [][]int {
	paths := make([][]int, 0)
	if root == nil {
		return paths
	}
	pathAux(root, 0, sum, make([]int, 0), &paths)
	return paths
}
