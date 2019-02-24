# !/usr/bin/env python3
# -*- coding:utf-8 -*-
# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:    # 100ms
    def merge(self,intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        n = len(intervals)
        if n <= 1:
            return intervals
        intervals = sorted(intervals,key= lambda x : x.start)
        res = []
        a = intervals[0].start
        b = intervals[0].end
        for i in range(1,n):
            if intervals[i].start <= b:
                b = max(intervals[i].end,b)
            else:
                res.append([a,b])
                a = intervals[i].start
                b = intervals[i].end
        res.append([a,b])
        return res






