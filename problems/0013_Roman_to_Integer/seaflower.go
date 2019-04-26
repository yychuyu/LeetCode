//改用map 不要用2個array ,加速優化
//方法跟12題類似

func RomanToInt(s string) int {
	symbolToI := map[string]int{
		"I": 1,
		"V": 5,
		"X": 10,
		"L": 50,
		"C": 100,
		"D": 500,
		"M": 1000,
	}

	n := len(s)
	number := 0
	i := 0
	var currentBase int

	for i < n {
		currentSum := 0
		prevBase := symbolToI[string(s[i])]
		for j := i; j < n; j++ {
			currentBase = symbolToI[string(s[j])]
			if currentBase != prevBase {
				break
			}
			i++
			currentSum += currentBase
		}

		//例如: IV or IX
		if prevBase < currentBase {
			currentSum = currentBase - prevBase
			i++
		}

		number += currentSum
	}

	return number
}
