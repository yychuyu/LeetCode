import (
	"sort"
)

func threeSum(nums []int) [][]int {
	//input: [-1,0,1,2,-1,-4]
	ans := [][]int{}
	sort.Ints(nums) //先排序,  [-4 -1 -1 0 1 2]
	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] { //過濾重複的 -1
			continue
		}
		j, k := i+1, len(nums)-1 //一開始 i代表-4 j代表-1 k代表2, 固定i之後 接下來就類似2Sum
		for j < k {
			if j > i+1 && nums[j] == nums[j-1] {
				j++
				continue
			}
			if k < len(nums)-1 && nums[k] == nums[k+1] {
				k--
				continue
			}
			sum := nums[i] + nums[j] + nums[k]
			if sum == 0 {
				ans = append(ans, []int{nums[i], nums[j], nums[k]})
				j++
				k--
			} else if sum < 0 {
				j++
			} else {
				k--
			}
		}
	}
	return ans
}