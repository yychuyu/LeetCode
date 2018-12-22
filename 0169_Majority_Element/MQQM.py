'''
  题目：
  给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
  你可以假设数组是非空的，并且给定的数组总是存在众数。
  
  做法：遍历一趟，记录各个元素出现的次数。
  
  参考：
  https://blog.csdn.net/qq_34364995/article/details/80544139
'''
class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = {}
        for i in nums:
            if i in dic.keys():
                dic[i] += 1
            else:
                dic[i] = 1
        
        for key in dic.keys():
            if dic[key] > len(nums)//2:
                return key
             
'''              
还有一种(最简单的)做法：因为众数出现的次数过半了，所以排序后，最中间的值必定是众数。
class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sorted(nums)[len(nums)//2]
'''
