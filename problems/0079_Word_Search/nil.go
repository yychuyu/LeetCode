package WordSearch

func search(board [][]byte, word string, sx, sy, rows, cols int, visited []bool) bool {
	if word == "" {
		return true
	}
	if sx < 0 || sx >= rows || sy < 0 || sy >= cols ||
		board[sx][sy] != word[0] || visited[sx*cols+sy] {
		return false
	}
	res := false
	visited[sx*cols+sy] = true
	for _, item := range [][]int{{0, 1}, {-1, 0}, {0, -1}, {1, 0}} {
		res = res || search(board, word[1:], sx+item[0], sy+item[1], rows, cols, visited)
	}
	if !res {
		visited[sx*cols+sy] = false
	}
	return res
}

func exist(board [][]byte, word string) bool {
	if word == "" {
		return false
	}
	rows := len(board)
	if rows == 0 {
		return false
	}
	cols := len(board[0])
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			visited := make([]bool, rows*cols)
			if search(board, word, i, j, rows, cols, visited) {
				return true
			}
		}
	}
	return false
}
