package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {
	root := &TreeNode{1,
		&TreeNode{2, &TreeNode{3, nil, nil}, &TreeNode{4, nil, nil}},
		&TreeNode{2, &TreeNode{4, nil, nil}, &TreeNode{3, nil, nil}},
	}
	fmt.Println(isSymmetric(root))
}

func isSymmetric(root *TreeNode) bool {
	return isMirror(root, root)
}

// isMirror ...
func isMirror(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if left == nil || right == nil {
		return false
	}

	return left.Val == right.Val && isMirror(left.Left, right.Right) && isMirror(left.Right, right.Left)
}
