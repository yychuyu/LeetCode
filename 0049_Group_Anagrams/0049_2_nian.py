class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """       
        hash_result = dict()
        result = []
        pos = 0
        for item in strs:
            mul = self.multi(item)
            if(mul not in hash_result):
                hash_result[mul] = pos
                result.append([])
                result[pos].append(item)
                pos+=1
            else:
                result[hash_result[mul]].append(item)
        return result
     
    
    def multi(self,s):
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103]; 
        result = 1
        for i in s:
            result *= primes[(ord(i)-97)]
        return result
