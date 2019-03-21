func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	temp := x
	var x2 int
	for temp != 0 {
		pop := temp % 10
		temp = temp / 10
		x2 = x2*10 + pop
	}
	if x2 == x {
		return true
	}
	return false
}

// 先把原數字%10 在 /10 依照此步驟來反轉