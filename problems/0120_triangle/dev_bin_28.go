package main

import (
	"fmt"
)

func main() {
	triangle := [][]int{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}
	result := minimumTotal2(triangle)
	fmt.Println(result)
}

func minimumTotal(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}

	for i := len(triangle) - 2; i >= 0; i-- {
		for j := 0; j < len(triangle[i]); j++ {
			triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
		}
	}
	return triangle[0][0]
}

// 思路:
// 从第一行开始遍历到倒数第二行
// 逐个遍历每一行的每个元素
// 如果当前元素是第一个，则计算出下一行第一第二个元素中较小的那个值
// 如果当前元素不是第一个，则只需要把对应下一行的两个相邻元素的右边那个与之前计算出较小的那个元素进行比较，因为左边的已经比对过了。
func minimumTotal2(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}
	result := triangle[0][0]
	for i := 0; i < len(triangle)-1; i++ {
		rowMin := 0
		for j := 0; j < len(triangle[i]); j++ {
			if j == 0 {
				rowMin = min(triangle[i+1][j], triangle[i+1][j+1])
			} else {
				rowMin = min(rowMin, triangle[i+1][j+1])
			}
		}
		result += rowMin
	}
	return result
}

// min ...
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
