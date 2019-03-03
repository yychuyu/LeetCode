class Solution(object):
    def permuteUnique(self, nums):
        result = []
        zero = []
        cur = []
        nums.sort()
        for i in range(len(nums)):
            zero.append(0)
        def DFS(self,nums,n,d,cur):
            if(d == n):
                result.append(cur[:])
                return
            else:
                for i in range(len(nums)):
                    if(zero[i]==1 or i>0 and nums[i-1] == nums[i] and zero[i-1]==0 ):
                        continue
                    else:
                        zero[i]=1
                        cur.append(nums[i])
                        DFS(self,nums,n,d+1,cur)
                        cur.pop()
                        zero[i]=0
        DFS(self,nums,len(nums),0,cur)
        return result
