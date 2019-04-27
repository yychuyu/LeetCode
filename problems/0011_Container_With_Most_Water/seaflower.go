func MaxArea(height []int) int {
	if height == nil || len(height) < 2 {
		return 0
	}
	var left = 0
	var right = len(height) - 1
	var result = 0
	var temp = 0
	for left < right {
		temp = (right - left) * min(height[left], height[right])
		result = max(result, temp)
		if height[left] < height[right] {
			left++
		} else {
			right--
		}
	}
	return result
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
