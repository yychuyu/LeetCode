class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        result=""
        d = {1:'I',5:'V',10:'X',50:'L',100:'C',500:'D',1000:'M'}
        for i in range(3,-1,-1):
            thisnum = int(num/(10**i))
            thisrom = d[10**i]
            num = int(num%(10**i))
            if(thisnum==4):
                result+=d[10**i]+d[5*10**i]
                continue
            if(thisnum==9):
                result+=d[10**i]+d[10**(i+1)]
                continue
            if(thisnum>=5 and thisnum<9):    
                result+=d[5*10**i]
                thisnum-=5
            for j in range(thisnum):
                   result+=d[10**i]                
        return result
