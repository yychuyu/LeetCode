package DistinctSubsequences
// 直接暴力的解法
//func aux(str, template string, now, length int, cnt *int) {
//	if length == len(template) {
//		*cnt++
//		return
//	}
//	if now == len(str) {
//		return
//	}
//	for index := now; index < len(str); index++ {
//		if str[index] == template[length] {
//			aux(str, template, index+1, length+1, cnt)
//		}
//	}
//}

func numDistinct(s string, t string) int {
	dp := make([][]int, len(s)+1)
	for index := 0; index <= len(s); index++ {
		dp[index] = make([]int, len(t)+1)
		dp[index][0] = 1
	}
	for index := 1; index <= len(s); index++ {
		for inner := 1; inner <= len(t); inner++ {
			if s[index-1] == t[inner-1] {
				dp[index][inner] = dp[index-1][inner-1]+dp[index-1][inner]
			} else {
				dp[index][inner] = dp[index-1][inner]
			}
		}
	}
	return dp[len(s)][len(t)]
}
