#
# @lc app=leetcode.cn id=566 lang=python3
#
# [566] 重塑矩阵
#
class Solution:
    def matrixReshape(self, nums, r: int, c: int):
        ori_list = self.expandList(nums)
        if r*c != len(ori_list):
            return nums

        out_list = []

        for i in range(r):
            out_list.append([])
            for j in range(c):
                out_list[i].append(ori_list.pop(0))

        return out_list

    def expandList(self, nums):
        ori_list = []
        for item in nums:
            if isinstance(item, list):
                ori_list.extend(self.expandList(item))
            else:
                ori_list.append(item)

        return ori_list


'''
s = Solution()
out = s.matrixReshape([[1,2,7,6],[8,9,0,5],[3,4,11,22]], 2, 6)

print(out)
'''   

'''
别人解法，简洁易懂！
A = [x for row in nums for x in row ]
if r * c == len(A):
    return [A[i*c : (i + 1)*c] for i in range(r) ]
else:
    return nums
'''
    