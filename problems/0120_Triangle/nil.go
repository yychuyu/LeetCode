package Triangle

func min(x, y int) int {
	if x > y {
		return y
	}
	return x
}

func minimumTotal(triangle [][]int) int {
	if triangle == nil {
		return 0
	}
	for row := len(triangle)-2; row >= 0; row -- {
		for col := 0; col < len(triangle[row]); col ++ {
			triangle[row][col] = triangle[row][col]+min(triangle[row+1][col], triangle[row+1][col+1])
		}
	}
	return triangle[0][0]
}
