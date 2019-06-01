package main

import (
	"fmt"
)

func main() {
	triangle := [][]int{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}
	result := minimumTotal(triangle)
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

// min ...
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
