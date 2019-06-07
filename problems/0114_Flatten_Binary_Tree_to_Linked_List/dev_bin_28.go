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
	left3 := TreeNode{3, nil, nil}
	right4 := TreeNode{4, nil, nil}
	right6 := TreeNode{6, nil, nil}
	left2 := TreeNode{2, &left3, &right4}
	right5 := TreeNode{5, nil, &right6}
	root := TreeNode{1, &left2, &right5}
	flatten(&root)

	cur := &root
	for {
		fmt.Println(cur.Val)
		if cur.Right != nil {
			cur = cur.Right
		} else {
			break
		}
	}
}

// flatten ...
func flatten(root *TreeNode) {
	if root != nil {
		flatten(root.Left)
		flatten(root.Right)
		tmp := root.Right
		root.Right = root.Left
		root.Left = nil
		for {
			if root.Right != nil {
				root = root.Right
			} else {
				break
			}
		}
		root.Right = tmp
	}
}
