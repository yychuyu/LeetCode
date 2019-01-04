package main

import "fmt"

func main() {
	fmt.Println(LengthOfLongestSubstring("abcabcbb"))
	fmt.Println(LengthOfLongestSubstring("aab"))
	fmt.Println(LengthOfLongestSubstring("bbbbb"))
	fmt.Println(LengthOfLongestSubstring("pwwkew"))

}

//LengthOfLongestSubstring 沒有重複字元的最長字串
func LengthOfLongestSubstring(s string) int {
	// var max = 0   //找到的字串長度
	// var index int //index代表 初始化的指標
	// var j int     //j代表 後續的指標要跟index代表來比對
	// //特別案例
	// if len(s) < 0 {
	// 	return 0
	// } else if len(s) == 1 {
	// 	return 1
	// } else {
	// 	for ; index < len(s); index++ {
	// 		for j = index + 1; j < len(s); j++ {
	// 			fmt.Println("第1個for loop index =", index)
	// 			if s[index:index+1] == s[j:j+1] {
	// 				fmt.Println("找到重複的字元 =>", s[index:index+1], ",index =>", index)
	// 				fmt.Println("字串 =>", s[index:j], ",j =>", j)
	// 				if max < len(s[index:j]) {
	// 					max = len(s[index:j])
	// 				}
	// 				break
	// 			}
	// 		}
	// 	}
	// 	if max == 0 {
	// 		fmt.Println("MAX ==", max)
	// 		max = len(s)
	// 	}
	// 	return max
	// }

	m := [128]int{} // 基本的字元有127個
	for i := 0; i < 128; i++ {
		m[i] = -1
	}
	length, start := 0, -1
	for i := 0; i < len(s); i++ {
		if m[s[i]] > start { // 如果該字元重複, 紀錄該字元得最大位置
			start = m[s[i]]
		}
		m[s[i]] = i           // 将存在的字符记录为键, 字符在字符串中的位置记录为值
		if i-start > length { // 当前位置 - 已经记录的最大位置, 为该次重复子串的最大长度
			length = i - start
		}
	}
	return length
}
