
//快速版,使用dp來處理
func isMatch(s string, p string) bool {
	n, m := len(s), len(p)
	dp := make([][]bool, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]bool, m+1)
	}
	dp[0][0] = true
	for j := 2; j <= m; j++ {
		if p[j-1] == '*' {
			dp[0][j] = dp[0][j-2]
		}
	}
	// fmt.Printf("%#v\n",dp[0])
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if s[i-1] == p[j-1] || p[j-1] == '.' {
				dp[i][j] = dp[i-1][j-1]
				continue
			}
			if p[j-1] == '*' {
				if p[j-2] != '.' && p[j-2] != s[i-1] {
					dp[i][j] = dp[i][j-2]
				} else {
					dp[i][j] = dp[i][j-2] || dp[i-1][j]
				}
			}
		}
	}
	// for _, r := range dp{
	//     fmt.Printf("%v\n",r)
	// }
	return dp[n][m]
}


func isMatch2(s string, p string) bool {
		r1, w1 := utf8.DecodeRuneInString(p)
		if w1 <= 0 {
			break
		}
		p = p[w1:]

		r2, w2 := utf8.DecodeRuneInString(p)
		if r2 == '*' {
			// Zero or more
			p = p[w2:]
			for true {
				if ok := RegularExpressionMatching(s, p); ok {
					return true
				}
				r3, w3 := utf8.DecodeRuneInString(s)
				if (r1 == '.' || r1 == r3) && w3 > 0 {
					s = s[w3:]
				} else {
					break
				}
			}
		} else {
			// One
			r3, w3 := utf8.DecodeRuneInString(s)
			if w3 <= 0 || !(r1 == '.' || r1 == r3) {

				return false
			}
			s = s[w3:]
		}
	}

	return len(s) <= 0
}