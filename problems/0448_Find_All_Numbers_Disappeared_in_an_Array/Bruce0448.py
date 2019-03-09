# 448 solution by Bruce


# solution one :正负标志位
# url：https://blog.csdn.net/u010429424/article/details/69499568

Class Solution(object):
    def findDisappearedNumbers(self, nums):
	    for i in range(len(nums)):
		    j = （abs(nums[i]) - 1） # 这里注意列表用的方括号而不是圆括号，可以在LeeCode 的playground调试。再加个括号也可以的，优先性不好把握的话。
			nums[j] = - abs(nums[j])
		return [i+1 for i in range(len(nums)) if nums[i] > 0]
"""
Runtime: 208 ms, faster than 37.25% of Python3 online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 18.8 MB, less than 46.08% of Python3 online submissions for Find All Numbers Disappeared in an Array.

"""		
		
# solution Two
# others：《Find All Numbers Disappeared in an Array》，顺便简单解释一下友题《Find All Duplicates in an Array》。
#          此解法三，也是Solution one 的C实现。
# url：https://blog.csdn.net/yutianzuijin/article/details/53861485






















"""