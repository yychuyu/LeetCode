package main

import "fmt"

func main() {
	nums1 := []int{1, 2}
	nums2 := []int{3, 4}
	Q := findMedianSortedArrays(nums1, nums2)
	fmt.Println(Q)
	fmt.Println(addTwoNumbers(nums1, nums2))
}

//最簡單的就是將2個array合起來，然後開始計算，
//當長度是奇數時，中位數 = x((n+1)/2)，
//當長度是偶數時，中位數 = x((n/2)+x(n/2+1))/2
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	i, j := 0, 0
	nums3 := []int{}
	for i < len(nums1) && j < len(nums2) {
		if nums1[i] < nums2[j] {
			nums3 = append(nums3, nums1[i])
			i = i + 1
		} else {
			nums3 = append(nums3, nums2[j])
			j = j + 1
		}
	}
	if i < len(nums1) {
		for ; i < len(nums1); i++ {
			nums3 = append(nums3, nums1[i])
		}
	}
	if j < len(nums2) {
		for ; j < len(nums2); j++ {
			nums3 = append(nums3, nums2[j])
		}
	}
	lenSums3 := len(nums3)
	if lenSums3%2 == 0 {
		return (float64(nums3[lenSums3/2-1]) + float64(nums3[lenSums3/2])) / 2.0
	} else {
		return float64(nums3[(lenSums3+1)/2-1])
	}
}
