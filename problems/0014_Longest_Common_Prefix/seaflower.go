import "strings"

func LongestCommonPrefix(strs []string) string {
	//strings.HasPrefix 檢查前墜是否存在
	if len(strs) == 0 {
		return ""
	}
	if len(strs) == 1 {
		return strs[0]
	}

	//[aim air aimless]

	prefix := strs[0]                //把第一個給到前墜字串 aim
	for i := 1; i < len(strs); i++ { //開始逐一訪問, 從1開始就好, 跳過自己
		for strings.HasPrefix(strs[i], prefix) == false { //當這個字串沒有找到時, (air, aim) = false
			prefix = string([]rune(prefix)[:len(prefix)-1]) // aim 往前一位 prefix = ai, 繼續找, 直到true
		}
	}
	return prefix
}