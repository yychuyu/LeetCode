package SubstringwithConcatenationofAllWords

func findSubstring(s string, words []string) []int {
	res := make([]int, 0)
	wordsLen := len(words)
	if wordsLen == 0 {
		return res
	}

	wordLen := len(words[0])
	length := wordLen * wordsLen
	if len(s) < length {
		return res
	}
	wordsMap := make(map[string]int)
	for _, item := range words {
		wordsMap[item]++
	}
	keywords := len(wordsMap)
	start, end := 0, length-1
	for ; end < len(s); end, start = end+1, start+1 {
		tMap := make(map[string]int)
		required := 0
		for i := start; i <= end; i += wordLen {
			str := s[i : i+wordLen]
			tMap[str]++
			cnt, ok := wordsMap[str]
			if !ok {
				break
			}
			if cnt == tMap[str] {
				required++
			}
		}
		if required == keywords {
			res = append(res, start)
		}
	}
	return res
}
