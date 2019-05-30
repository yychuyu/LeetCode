package FlattenBinaryTreetoLinkedList

import (
	"for-an-offer/zs-leetcode-go/types"
)

func aux(root *types.TreeNode, lastNode **types.TreeNode){
	pCurrent := root
	left, right := pCurrent.Left, pCurrent.Right
	pCurrent.Left = *lastNode
	if *lastNode != nil {
		(*lastNode).Right = pCurrent
	}
	*lastNode = pCurrent
	if left != nil {
		aux(left, lastNode)
	}
	if right != nil {
		aux(right, lastNode)
	}
}
func flatten(root *types.TreeNode)  {
	if root != nil {
		var lastNode *types.TreeNode
		aux(root, &lastNode)
		for ; lastNode.Left != nil; lastNode = lastNode.Left{}
		root = lastNode
		lastNode = root
		for ; lastNode != nil; lastNode = lastNode.Right {
			lastNode.Left = nil
		}
	}

}
