package main

import "fmt"

// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的 两个 整数。
// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
// 示例:
// 给定 nums = [2, 7, 11, 15], target = 9
// 因为 nums[0] + nums[1] = 2 + 7 = 9 所以返回 [0, 1]

func main() {
	nums := []int{11, 7, 2, 5, 6}
	target := 9
	fmt.Println(twosum(nums, target))
}

func twosum(nums []int, target int) []int {
	length := len(nums)
	//法1
	//var ans int
	// for i := 0; i < length; i++ {
	// 	for j := (i + 1); j < length; j++ {
	// 		ans = nums[i] + nums[j]
	// 		if ans == target {
	// 			return []int{i, j}
	// 		}
	// 	}
	// }
	//法2
	ansMap := make(map[int]int)
	for i := 0; i < length; i++ {
		ansMap[nums[i]] = i //用map(key=數字, value=索引)存下每個數字
	}
	for i := 0; i < length; i++ {
		index, ok := ansMap[target-nums[i]]
		if ok { //如果 target-nums[i] 找的到,代表存在
			return []int{i, index}
		}
	}
	return nil
}
