class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits = digits[::-1]
        carry = 1
        for i in range(len(digits)):
            sums = digits[i]+carry
            carry ,digits[i] = sums // 10 , sums % 10 
        if carry:
            digits.append(1)
        return digits[::-1]
            
