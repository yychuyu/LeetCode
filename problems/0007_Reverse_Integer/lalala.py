# -*- coding: utf-8 -*-
"""
Created on Sun Nov 25 15:34:23 2018

@author: Administrator
"""

class Reverse:

    def __init__(self, num):
        self.judge = int(num)
        abs_num = str(abs( int(num) ))
        self.num = list(abs_num)
        
    def re_method(self):
        
        for i  in range(0, len(self.num)//2 ):
            
            a = self.num[i]
            self.num[i] = self.num[len(self.num)-i-1]
            self.num[len(self.num)-i-1] = a
        self.b = ''.join(self.num)
        
        if self.judge >=0:
         print("the reverse integer is : {}".format(self.b))
        else:
         print("the reverse integer is :-{}".format(self.b))


integer = input("请输入一个整数：")

if -2**32 <= int(integer) <= 2**32-1:
 re_integer = Reverse(integer)

 re_integer.re_method()
else:
 print(0)
