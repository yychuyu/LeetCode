func longestValidParentheses(s string) int {
	strLength := len(s)
	index := 0
	maxLength := 0
	for index < strLength {
		// 遇到( 匹配到最后， 拿一个长度，
		if s[index] == '(' {
			walk := index + 1
			cnt := 0      // 计算括号的对数
			count := 1    // 遇到( +1, )-1
			mid := 0      // 记录内在(括号的数量
			innerMax := 0 // 用来记录栈内不存数据的最大值
			for walk < strLength {
				if s[walk] == ')' {
					count -= 1
					if count < 0 {
						break
					}
					cnt += 2
					if mid != 0 {
						mid -= 1
					}
					if mid == 0 {
						// 说放入这个)后栈内不存在多余的(
						innerMax = cnt
					}
				} else {
					mid += 1
					count += 1
				}
				walk += 1
			}
			if innerMax != 0 {
				index = index + innerMax
			} else {
				index += 1
			}
			if maxLength < innerMax {
				maxLength = innerMax
			}
		} else {
			index += 1
		}
	}
	return maxLength
}

