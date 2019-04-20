class Solution:
	def nthUglyNumber(self, n: int) -> int:
		ids = [0, 0, 0]
		uglys = [1,]
		for i in range(1, n):
			a = uglys[ids[0]] * 2
			b = uglys[ids[1]] * 3
			c = uglys[ids[2]] * 5
			min_ = min(a, b, c)
			if a == min_: ids[0] += 1
			if b == min_: ids[1] += 1
			if c == min_: ids[2] += 1
			uglys.append(min_)
		return uglys[-1]
