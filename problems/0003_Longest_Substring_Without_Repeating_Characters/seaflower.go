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
	//暴力for loop, 超時就不貼了

	//法2的想法: 假設xbyauxalopmnbu
	//a重複: 不是xbyaux最長就是, uxalopmnbu最長
	//從頭開始, 找到重複的地方就把start指標指到重複之前的"u"再開始找
	m := [256]int{} // ASCII 0~255
	for i := 0; i < 256; i++ {
		m[i] = -1
	}

	length, start := 0, -1

	for i := 0; i < len(s); i++ {
		// 如果該字元被找過, 則紀錄該字元已經紀錄的最大位置
		if m[s[i]] > start {
			start = m[s[i]]
		}
		// 將存在的字元紀錄為key, 字元在字串中的位置紀錄為value
		m[s[i]] = i //value
		// 當前位置 - 已經紀錄的最大位置
		if i-start > length {
			length = i - start
		}
	}

	return length
}
