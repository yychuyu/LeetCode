class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root:
            return self.judge(root.left, root.right)
        else:
            return True

    def judge(self, left, right):
        if left and right:
            return self.judge(left.left, right.right) and self.judge(left.right,
                                                                     right.left) and left.val == right.val
        else:
            return not left and not right