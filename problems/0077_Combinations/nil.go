package Combinations

func aux(start, end int, now int, stack *[]int, res *[][]int) {
	if now == 0 {
		tmp := make([]int, len(*stack))
		copy(tmp, *stack)
		*res = append(*res, tmp)
		return
	}
	if start > end {
		return
	}
	*stack = append(*stack, start)
	aux(start+1, end, now-1, stack, res)
	*stack = (*stack)[:len(*stack)-1]
	aux(start+1, end, now, stack, res)
}

func combine(n int, k int) [][]int {
	res := make([][]int, 0)
	stack := make([]int, 0)
	aux(1, n, k, &stack, &res)
	return res
}
