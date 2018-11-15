# !/usr/bin/env python3
# -*- coding:utf-8 -*-

'leetcode-905.按奇偶排序数组:给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。你可以返回满足此条件的任何数组作为答案。'

class Solution:    # 92ms
	def sortArrayByParity1(self,A):
		"""
        :type A: List[int]
        :rtype: List[int]
        """
		return sorted(A,key = lambda x: x % 2)


	def sortArrayByParity2(self,A):  # 96ms
		"""
	    :type A: List[int]
	    :rtype: List[int]
	    """
	    a = []
	    b = []
	    for i in A:
	    	if i % 2 == 0:
	    		a.append(i)
	    	else:
	    		b.append(i)
	    return a + b


    def sortArrayByParity3(self,A):   # 92ms
		"""
        :type A: List[int]
        :rtype: List[int]
        """
        return [i for i in A if i % 2 == 0] + [i for i in A if i % 2 == 1]




