package main

import (
	"fmt"
)

func main() {
	nums := []int{2, 7, 11, 15}
	result := twoSum(nums, 9)
	if len(result) == 2 {
		fmt.Println(result)
	} else {
		fmt.Println("没有找到")
	}
}

// twosum ...
func twoSum(nums []int, target int) []int {
	numsMap := make(map[int]int)
	for key, value := range nums {
		othter := target - value
		if index, ok := numsMap[othter]; ok {
			return []int{index, key}
		}
		numsMap[value] = key
	}
	return []int{}
}
