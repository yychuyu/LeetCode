package LargestNumber

import (
	"bytes"
	"fmt"
	"sort"
)


type sortArray []int

func (sa sortArray) Len() int{
	return len(sa)
}

func (sa sortArray) Swap(i, j int) {
	sa[i], sa[j] = sa[j], sa[i]
}
func (sa sortArray) Less(i, j int) bool {
	return fmt.Sprintf("%d%d", sa[i], sa[j]) > fmt.Sprintf("%d%d", sa[j], sa[i])
}

func largestNumber(nums []int) string {
	buf := bytes.NewBufferString("")
	sort.Sort(sortArray(nums))
	zero := false
	for _, item := range nums {
		if item != 0 {
			zero = true
		}
		buf.WriteString(fmt.Sprintf("%d", item))
	}
	if !zero {
		return "0"
	}
	return buf.String()
}
