class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.ret = True
        def dfsCmp(p, q):
            if self.ret:
                if p and q:
                    if p.val != q.val:
                        self.ret = False
                        return self.ret
                    else:
                        q.left, q.right = q.right, q.left
                        dfsCmp(p.left, q.left)
                        dfsCmp(p.right, q.right)
                elif p or q:
                    self.ret = False
        if root:
            if root.left and root.right:
                dfsCmp(root.left, root.right)
            elif root.left or root.right:
                return False
        return self.ret