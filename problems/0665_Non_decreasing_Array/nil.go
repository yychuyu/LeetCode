package NondecreasingArray


func judge(nums []int) bool {
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] > nums[i+1] {
			return  false
		}
	}
	return true
}

func checkPossibility(nums []int) bool {
	tmp := make([]int, len(nums))
	copy(tmp, nums)
	for i := 0; i < len(nums); i++ {
		old := nums[i]
		if i > 0 {
			tmp[i] = tmp[i-1]
		} else {
			tmp[i] = -(1<<10)
		}
		if judge(tmp) {
			return true
		}
		tmp[i] = old
	}
	return false
}