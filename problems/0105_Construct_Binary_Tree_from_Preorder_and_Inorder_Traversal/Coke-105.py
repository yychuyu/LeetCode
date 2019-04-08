class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        
        if not preorder:
            return None
        root = TreeNode(preorder[0])
        #找到根节点在中序遍历中的下标
        n = inorder.index(root.val)
        root.left = self.buildTree(preorder[1:n+1],inorder[:n])
        root.right = self.buildTree(preorder[n+1:],inorder[n+1:])
        return root