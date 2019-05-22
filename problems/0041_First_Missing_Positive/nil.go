package FirstMissingPositive


func firstMissingPositive(nums []int) int {
	cnt := 1
	for i := 0; i < len(nums); i++ {
		if cnt == nums[i] {
			cnt ++
			i = -1
		}
	}
	return cnt
}
