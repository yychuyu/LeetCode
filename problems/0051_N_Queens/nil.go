package main

import "bytes"

func aux(row, n int, line []int,  res *[][]string) {
    if row == n {
        // 生成数组
        tmp := []string{}
        for _, item := range line {
            buf := bytes.NewBufferString("")
            for in := 0; in < n; in ++ {
                if in == item {
                    buf.WriteString("Q")
                } else {
                    buf.WriteString(".")
                }
            }
            tmp = append(tmp, buf.String())
        }
        (*res) = append(*res, tmp)
    } else {
        for i := 0; i < n; i++ {
            flag := true
            line[row] = i
            for j := 0; j < row; j++ {
                if line[j] == line[row] || row-j==line[row]-line[j] || row-j==line[j]-line[row] {
                    flag = false
                    break
                }
            }
            if flag {
                aux(row+1, n, line, res)
            }
        }
    }
}

func solveNQueens(n int) [][]string {
    res := make([][]string, 0)
    line := make([]int, n)
    aux(0, n, line, &res)
    return res
}
