package HouseRobber


func rob(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}
	if length == 1 {
		return nums[0]
	}
	res := nums[0]
	maxIndex := 0
	for i := 1; i < length; i++ {
		if i != 1 {
			for j := maxIndex; j < i-1; j++ {
				if nums[j] > nums[maxIndex] {
					maxIndex = j
				}
			}
			nums[i] += nums[maxIndex]
			if nums[i] > res {
				res = nums[i]
			}
		} else {
			if nums[i] > res {
				res = nums[i]
			}
		}
	}
	return res
}
