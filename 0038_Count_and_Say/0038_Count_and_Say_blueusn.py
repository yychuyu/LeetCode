class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==1:
            return '1'
        beforeSeq = '1'
        afterSeq = ''
        while n>1:
            key = beforeSeq[0]
            currentLen = len(beforeSeq)
            count = 0
            afterSeq = ''
            for i in range(currentLen):
                if key == beforeSeq[i]:
                    count += 1
                    if i + 1 == currentLen:
                        afterSeq += (str(count) + key)
                else:
                    afterSeq += (str(count) + key)
                    key = beforeSeq[i]
                    count = 1
                    if i + 1 == currentLen:
                        afterSeq += (str(count) + key)
            beforeSeq = afterSeq
            n -= 1
        return beforeSeq