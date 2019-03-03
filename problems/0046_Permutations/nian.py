class Solution(object):
    def permute(self, nums):
        cur = []
        used = []
        result = []
        for i in range(len(nums)):
            used.append(0)
        def DFS(nums,n,d,cur,used):
            if(n==d):
                result.append(cur[:])   #必须是添加cur[:]是数组的复制，否则添加的是数组的引用，会出现问题
                return
            else:
                for i in range(len(nums)):
                    if(used[i]==1):
                        continue
                    else:
                        used[i]=1
                        cur.append(nums[i])
                        DFS(nums,n,d+1,cur,used)
                        cur.pop()
                        used[i]=0
        DFS(nums,len(nums),0,cur,used)
        return result
