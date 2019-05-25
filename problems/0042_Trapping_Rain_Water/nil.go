package TrappingRainWater


func findIndex(nums []int) int {
	maxIndex := 0
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[maxIndex] {
			maxIndex = i
		}
	}
	return  maxIndex
}

func trap(height []int) int {
	if len(height) ==0 {
		return 0
	}
	maxIndex := findIndex(height)
	now := height[0]
	start := 1
	cnt := 0
	for ;start < maxIndex; start++ {
		if height[start] > now {
			now = height[start]
		} else {
			cnt += now-height[start]
		}
	}
	now = height[len(height)-1]
	end := len(height)-2
	for ; end > maxIndex; end-- {
		if height[end] > now {
			now = height[end]
		} else {
			cnt += now - height[end]
		}
	}
	return cnt
}
