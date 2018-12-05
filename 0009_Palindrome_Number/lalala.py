# -*- coding: utf-8 -*-
"""
Created on Sun Dec  2 15:47:34 2018

@author: Administrator
"""
"""
9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
"""

#learn some thoughts from others
#type: int 
#rtype: bool

class Solution:
    
    def __init__(self, palin):
        
        self.palin = palin
        self.num_single = 0
        self.list_add = []
        
    def isPalindrome(self):
        
        while True:
            
            if self.palin < 0:
                return False
            if 0 <= self.palin <= 9:
                return True
              
            
            if self.palin != 0:
                self.palin = self.palin // 10
                self.num_single = self.palin
                self.list_add.append(self.num_single)
            else:
                break

            return self.list_add == self.list_add[::-1]
palin = int(input("please input an integer:"))
