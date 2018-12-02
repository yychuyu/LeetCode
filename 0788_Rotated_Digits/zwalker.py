class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        # 第一种
        # out=0
        # str1=''
        # for i in range(1,N+1):
        #     str1=str(i)
        #     if(str1.count('3')==0 and str1.count('4')==0 and str1.count('7')==0):
        #         if(str1.count('1')+str1.count('8')+str1.count('0')!=len(str1)):
        #             out+=1
        # return out
        
        # 第二种
        count = 0
        for num in range(N+1):
            strnum = str(num)
            if ('3' not in strnum and '4' not in strnum and  '7' not in strnum) and ('2' in strnum or '5' in strnum or '6' in strnum or '9' in strnum):
                count += 1
        return count


    
    
        