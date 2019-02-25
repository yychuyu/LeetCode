package main

import "fmt"

func main() {
	fmt.Println(convert("PAHNAPLSIIGYIR",3))
	fmt.Println(convert("aab",3))
	fmt.Println(convert("bbbbb",5))
	fmt.Println(convert("pwwkew",4))

}

/*
https://dev.twsiyuan.com/2017/10/leetcode-zigzag-conversion.html
*/
func convert(s string, numRows int) string {
	i, size := 0, len(s)
	ss := make([]string, numRows)
	for i < size {
		for j := 0; j < numRows && i < size; j++ {
			ss[j] += string(s[i])
			i++
		}
		for j := numRows - 2; j > 0 && i < size; j-- {
			ss[j] += string(s[i])
			i++
		}
	}
	var ret string
	for j := 0; j < numRows; j++ {
		ret += ss[j]
	}
	return ret
}
