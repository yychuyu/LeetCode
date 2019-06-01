package main

import (
	"fmt"
)

func main() {
	// triangle := [][]int{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}
	// triangle := [][]int{{-1}, {2, 3}, {1, -1, -3}}
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

// [[-1],[2,3],[1,-1,-3]]
func minimumTotal2(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}
	var j, left, right int
	for i := 1; i < len(triangle); i++ {
		triangle[i][0] = triangle[i-1][0] + triangle[i][0]
		for j = 1; j < len(triangle[i])-1; j++ {
			right = triangle[i-1][j]
			left = triangle[i-1][j-1]
			triangle[i][j] += min(left, right)
		}
		triangle[i][i] = triangle[i-1][i-1] + triangle[i][i]
	}
	result := triangle[len(triangle)-1][0]
	for _, value := range triangle[len(triangle)-1] {
		result = min(result, value)
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
