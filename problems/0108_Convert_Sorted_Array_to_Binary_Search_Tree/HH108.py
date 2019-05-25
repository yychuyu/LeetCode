class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """

        def constructTree(nums, start, end):
        	if start > end:
        		return None

        	mid = (start+end)/2
        	node = TreeNode(nums[mid])

        	if start == end:
        		return node

        	node.left = constructTree(nums, start, mid-1)
        	node.right = constructTree(nums, mid+1, end)
        	return node

        return constructTree(nums, 0, len(nums)-1)