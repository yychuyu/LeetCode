class Solution:
    """
    输入:3 
    000 - 0
    001 - 1
    011 - 3
    010 - 2
    110 - 6 4+2
    111 - 7	4+3
    101 - 5	4+1
    100 - 4	4+0
    [找规律]:可以看出3位的结果是在2的结果上加了一半，加上的一半 = 2位结果倒序排列然后在每一位上加上2的2次方（2**2） 
    """
    def grayCode(self, n: int) -> List[int]:
        ret = [0] * (n+5)
        ret[0] = [0]
        ret[1] = [0,1]
        ret[2] = [0,1,3,2]
        ret[3] = [0,1,3,2,6,7,5,4]
        if n >= 4:
            for i in range(4, n+1):
                add = 2 ** (i-1)    #int(math.pow(2,i-1))
                ret[i] = ret[i-1] + [add + i for i in ret[i-1][::-1]]
        
        return ret[n]
