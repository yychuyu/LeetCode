class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bull=0
        cow=0
        dic_secret = collections.defaultdict(lambda: 0)
        dic_guess = collections.defaultdict(lambda: 0)
        for i,j in zip(secret,guess):
            if(i==j):
                bull+=1
            else:
                dic_secret[i]+=1
                dic_guess[j]+=1
        for item in dic_guess:
            cow += min(dic_guess[item],dic_secret[item])
               
        return str(bull)+'A'+str(cow)+'B'
