//IntToRoman 整數轉羅馬數字
func IntToRoman(num int) string {
	if num <= 0 {
		return ""
	}
	var ans string
	var nums = []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	var symbols = []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	for i := 0; i < len(nums); i++ { //舉例: 進來的數字 3978,
		for num >= nums[i] { //第一次迴圈 3978 > 1000 第二次迴圈 2978 > 1000
			num -= nums[i]    //3978 - 1000 = 2978  2978 - 1000 = 1978
			ans += symbols[i] // 加一個M , 再加一個M 以此類推...
		}
	}
	return ans
}