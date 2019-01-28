package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	Q := longestPalindrome("上海自來水來自海上")
	fmt.Println(Q)
}

// Dynamic Programming 動態規劃演算法 O(N^2)
func longestPalindrome(s string) string {
	if strings.TrimSpace(s) == "" || len(s) < 1 {
		return ""
	}
	start, end := 0, 0
	for i := 0; i < len(s); i++ {
		len1 := expandAroundCenter(s, i, i)                //a [b] a bd 可能迴文數的中間數是一個 則從一個數開始兩邊擴散
		len2 := expandAroundCenter(s, i, i+1)              //a [bb] c 可能迴文數的中間數可以使兩個。從兩個開始兩邊是擴散
		len := int(math.Max(float64(len1), float64(len2))) //比較出兩個的最長的長度
		if len > end-start {
			//len=3  i=1
			start = i - (len-1)/2 //i:在這裡就是一個迴文數的中間數，（len-1）:是處理len可能是偶數的情況
			end = i + len/2
		}
	}
	return string(s[start : end+1])
}

func expandAroundCenter(s string, left, right int) int {
	L, R := left, right
	for L >= 0 && R < len(s) && s[L] == s[R] {
		L--
		R++
	}
	return R - L - 1 //計算出該串的長度
}
