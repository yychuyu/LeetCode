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
            sitem = self.sort(item)
            if(sitem not in hash_result):
                hash_result[sitem] = pos
                result.append([])
                result[pos].append(item)
                pos+=1
            else:
                result[hash_result[sitem]].append(item)
        return result
                                       
    def sort(self,s):
        return "".join(sorted(list(s)))
