class Solution(object):
    result=[]
    def levelOrder(self,root):
        self.result=[]
        if(root!=None):
            self.DFS(root,0)
        return self.result
    def DFS(self,node,depth):
         if(node!=None):
            print(node.val,depth)
            if(len(self.result)<depth+1):
                self.result.append([node.val])
            else:
                self.result[depth].append(node.val)
            self.DFS(node.left,depth+1)
            self.DFS(node.right,depth+1)
