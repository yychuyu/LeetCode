class Solution(object):
    def levelOrder(self, root):
        queue = []
        result = []
        if(root!=None):
            queue.append(root)
        while(queue):
            nextqueue = []
            thislevelval = []
            for node in queue:
                thislevelval.append(node.val)
                if(node.left!=None):
                    nextqueue.append(node.left)
                if(node.right!=None):
                    nextqueue.append(node.right)
            queue = nextqueue
            result.append(thislevelval)
        return result
