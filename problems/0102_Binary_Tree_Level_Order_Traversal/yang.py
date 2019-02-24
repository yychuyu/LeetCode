"""
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
"""
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        answer = []
        if not root:
            return answer
        level = [root]
        while level:
            result = [i.val for i in level if i]
            if result:
                answer.append(result)

            tmp = []
            for node in level:
                if node.left:
                    temp.append(node.left)
                if node.right:
                    tmp.append(node.right)

            level = tmp

        return answer
