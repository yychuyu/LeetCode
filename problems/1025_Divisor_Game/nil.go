package DivisorGame


func factor(n int) []int {
	res := make([]int, 0)
	for i := 1; i < n; i++ {
		if n % i == 0 {
			res = append(res, i)
		}
	}
	return res
}

func divisorGame(N int) bool {
	if N == 1 {
		return false
	}
	if N == 2 {
		return true
	}
	res := make([]bool, N+1)
	res[1] = false
	res[2] = true
	if N <= 2 {
		return res[N]
	}
	for i := 3; i <= N; i++ {
		flag := false
		fac := factor(i)
		for _, item := range fac {
			flag = flag || !res[i-item]
		}
		res[i] = flag
	}
	return res[N]
}