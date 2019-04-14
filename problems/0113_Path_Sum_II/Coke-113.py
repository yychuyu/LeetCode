class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if(root == None): return []
        self.res=[]
        self.tsum=sum
        def recursive(root,s,tmplist):
            if(root==None):
                return
            if(root.left==None and root.right==None):
                if(self.tsum==root.val+s):
                    self.res.append(tmplist+[root.val])
            if(root.left):
                recursive(root.left,s+root.val,tmplist+[root.val])
            if(root.right):
                recursive(root.right,s+root.val,tmplist+[root.val])
        recursive(root,0,[])
        return self.res