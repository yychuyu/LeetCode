# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []

        ret = []
        curLevelRet = []
        q = deque([root])
        lastNodeInCurLevel = root
        lastNodeInNextLevel = None
        while len(q):
            curNode = q.popleft()

            left = curNode.left
            if left is not None:
                q.append(left)
                lastNodeInNextLevel = left
            right = curNode.right
            if right is not None:
                q.append(right)
                lastNodeInNextLevel = right

            curLevelRet.append(curNode.val)
            if curNode == lastNodeInCurLevel:
                ret.append(curLevelRet)
                curLevelRet = []
                lastNodeInCurLevel = lastNodeInNextLevel

        return ret
