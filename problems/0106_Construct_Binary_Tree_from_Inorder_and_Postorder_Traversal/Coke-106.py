# Given inorder and postorder traversal of a tree, construct the binary tree.

# Note:
# You may assume that duplicates do not exist in the tree.

# For example, given

# inorder = [9,3,15,20,7]
# postorder = [9,15,7,20,3]
# Return the following binary tree:

#     3
#    / \
#   9  20
#     /  \
#    15   7

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if(postorder==None):return None
        if(len(postorder)==0): return None
        root=TreeNode(postorder[-1])
        j=inorder.index(root.val)
        root.left=self.buildTree(inorder[:j],postorder[:j])
        root.right=self.buildTree(inorder[j+1:],postorder[j:-1])
        return root