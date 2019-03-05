class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        length = len(gas)
        start=-1
        i=0
        end=-2
        tank=0
        while(start<length and start!=end):
            if(i>=length):
                i = i-length   #循环
            tank += gas[i]
            if(tank<cost[i]):
                start = max(start+1,i+1)
                # i,tank,end都需要重置
                i=start
                tank=0
                end=-2
            else:
                if(start==-1):
                    start=i
                # end也需要循环 不能简单的等于1+1
                end=(i+1)%length
                tank = tank-cost[i]          
                i+=1
        if(end==start):
            return start
        else:
            return -1
