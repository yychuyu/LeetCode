# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        ret = []
        if not intervals:
            return ret
        intervals.sort(key = lambda x : x.start)
        now =intervals[0]
        for inter in intervals[1:]:
            if inter.start <= now.end:
                now.start = min(inter.start,now.start)
                now.end = max(inter.end,now.end)
            else:
                ret.append(now)
                now = inter
        ret.append(now)
        return ret
