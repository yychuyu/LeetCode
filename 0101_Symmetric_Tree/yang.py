"""
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

     
       / \
      2   2
     / \ / \
    3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

        1
       / \
      2   2
       \   \
       3    3

Note:
Bonus points if you could solve it both recursively and iteratively. 
"""

class Solution(object):
    def isSymmetric(self, root):
        """
        :type: root: TreeNode
        :rtype: bool
        """
        def isSym(p, q):
            if not (p ad q):
                return p == q
            answer = (p.val == q.val and
                      isSym(p.left, q.right) and
                      isSym(p.right, q.left))
            return answer

        return isSym(root, root)
