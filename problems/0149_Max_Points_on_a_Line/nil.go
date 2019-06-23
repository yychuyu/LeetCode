package MaxPointsonaLine

import "fmt"

func gcd(x, y int) int {
	for x * y != 0{
		if x > y {
			x %= y
		} else {
			y %= x
		}
	}
	if x > y {
		return x
	}
	return y
}

func slope(a, b []int) string{
	// 考虑竖直的情况, 我的想法是不用竖直存储，用字符串
	xx := a[0] - b[0]
	yy := a[1] - b[1]
	// 特殊的斜率
	if xx == 0 {
		return "0xfffff"
	}
	if yy == 0 {
		return "0"
	}
	// 返回的是最后化简的分数形式
	flag := xx * yy < 0
	if yy < 0 {
		yy = -yy
	}
	if xx < 0 {
		xx = -xx
	}
	maxCommonDivisor := gcd(xx, yy)
	yy /= maxCommonDivisor
	xx /= maxCommonDivisor
	if flag {
		return fmt.Sprintf("-%d/%d",yy,xx)
	}
	return fmt.Sprintf("%d/%d", yy, xx)
}

func equal(a, b []int) bool {
	return a[0] == b[0] && a[1] == b[1]
}

func maxPoints(points [][]int) int {
	if len(points) == 0 {
		return 0
	}
	if len(points) == 1 {
		return 1
	}
	// 不多计算....下面的
	if len(points) == 2 {
		return 2
	}
	maxPoints := 0
	for index := 0; index < len(points)-1; index++ {
		tmp := make(map[string]int)
		doublePoint := 0
		tmpMax := 0
		for inner := index+1; inner < len(points); inner++ {
			// 重复点的情况
			if equal(points[index], points[inner]) {
				doublePoint++
				continue
			}
			xl := slope(points[index], points[inner])
			// 首次计算加上本身的点
			if tmp[xl] == 0 {
				tmp[xl] = 2
			} else {
				tmp[xl] += 1
			}
			if tmp[xl] > tmpMax {
				tmpMax = tmp[xl]
			}
		}
		if tmpMax == 0 {
			tmpMax += 1
		}
		tmpMax += doublePoint
		if tmpMax > maxPoints {
			maxPoints = tmpMax
		}
	}
	return maxPoints
}
