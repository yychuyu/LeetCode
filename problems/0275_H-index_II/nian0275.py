class Solution(object):
    def hIndex(self, citations):
        n = len(citations)
        ma = n-1
        mi = 0
        while(mi<=ma):
            mid = (ma+mi)/2
            print(ma,mi,mid)
            if(citations[mid]>=n-mid):
                ma = mid-1
            else:
                mi = mid+1
        return n-ma-1
