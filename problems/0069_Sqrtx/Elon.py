class Solution:
    def mySqrt(self, x: int) -> int:
        result= x
        while(abs(result*result - x) >=0.000001):
            result = (result + x/result) / 2
        return int(result)
        
        # l, r = 0, x
        # result = (l + r) / 2
        # while(abs(result*result - x)>=0.000001 or result*result < x):
        #     if result*result > x:
        #         r = result
        #     else:
        #         l = result
        #     result = (l + r) / 2
        # return int(result)
            
        # result = 0
        # while(result*result <= x):
        #     # print(result)
        #     result +=1
        # return result-1
        
        # result= x
        # while(abs(result*result - x) >=1):
        #     result = (result + x/result) / 2
        # return int(result)
    