

//數字反轉, 一直%10,再組裝來就好了
//123 123%10=3 12%10=2 1%10=1
//合起來就是321

func reverse(x int) int {
	reverseans := 0
	if x < 0 {
		x = -x
		for x > 0 {
			reverseans *= 10
			reverseans += x % 10
			x /= 10
		}

		reverseans = -reverseans
		if reverseans < -2147483648 {
			return 0
		}

		return reverseans
	}

	for x > 0 {
		reverseans *= 10
		reverseans += x % 10
		x /= 10
	}

	if reverseans > 2147483647 {
		return 0
	}

	return reverseans
}