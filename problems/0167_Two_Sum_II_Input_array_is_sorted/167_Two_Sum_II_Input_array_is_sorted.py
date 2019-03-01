class Solution(object):
    def twoSum(self, numbers, target):
        d = dict()
        for i in range(len(numbers)):
            com = target - numbers[i]
            if(d.has_key(numbers[i])):
                return [d[numbers[i]],i+1]
            d.setdefault(com,i+1)
