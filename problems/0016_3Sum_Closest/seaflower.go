import "sort"

func ThreeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	var ret int
	length := len(nums)
	sum := nums[0] + nums[1] + nums[2]
	ret = sum
	diff := abs(sum - target)

	for i := 0; i < length-2; i++ {
		for j, k := i+1, length-1; j < k; {
			sum = nums[i] + nums[j] + nums[k]
			if sum-target < 0 {
				j++
			} else {
				k--
			}
			if diff > abs(sum-target) {
				ret = sum
				diff = abs(sum - target)
			}
		}
	}
	return ret

}

func abs(in int) int {
	if in < 0 {
		return -in
	}
	return in
}