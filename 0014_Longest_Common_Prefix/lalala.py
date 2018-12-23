class Solution:
	
	def finding(self,*_tuple):
		
		l=0		#负责对循环计数
		m=[]		#负责最终和结果（列表）
		self.list = list(_tuple)
		for i in (0,len(self.list)-1):    #找出最短元素，决定最长前缀
			a=0
			b=len(self.list[0])
			if b>len(self.list[i]):
				b=len(self.list[i])
				a=i
	#测试代码：		print("最短为：",self.list[a])
		
		for j in range(0,len(self.list[a])):
			l=0
			for k in range(0,len(self.list)):
				if self.list[a][j]==self.list[k][j]:
					l+=1
				#测试代码：	print("实践：",l,"真理：",len(self.list))
				else:return m
			if l==len(self.list):
				m.append(self.list[a][j])
prefix = Solution()
a = "".join(prefix.finding("flower","flour","flow"))
print(a)
