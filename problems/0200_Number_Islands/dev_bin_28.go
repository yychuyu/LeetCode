package main

import (
	"fmt"
)

func main() {
	grid := [][]byte{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}}
	islandNum := numIslands(grid)
	fmt.Println(islandNum)
}

func numIslands(grid [][]byte) int {
	num := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == '1' {
				num++
				bfs(grid, i, j)
			}
		}
	}
	return num
}

// bfs ...
func bfs(grid [][]byte, i, j int) {
	if i >= 0 && i < len(grid) && j >= 0 && j < len(grid[i]) && grid[i][j] == '1' {
		grid[i][j] = '0'
		bfs(grid, i-1, j)
		bfs(grid, i+1, j)
		bfs(grid, i, j-1)
		bfs(grid, i, j+1)
	}
}
