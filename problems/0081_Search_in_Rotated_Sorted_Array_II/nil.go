package SearchinRotatedSortedArrayII

func binarySearch(nums []int, start ,end, target int) bool {
	for start <= end {
		mid := start + (end - start) / 2;
		if nums[mid] < target {
			start = mid + 1
		} else if nums[mid] > target {
			end = mid - 1
		} else {
			return true
		}
	}
	return false
}
func search(nums []int, target int) bool {
	start, end := 0, len(nums)-1
	if end == -1 {
		return false
	}
	if end == 0{
		if nums[0] == target {
			return true
		}
		return false
	}
	for ;end >=0 &&nums[end] <= nums[start]; end--{
		if end != len(nums)-1 && nums[end] > nums[end+1]{
			break
		}
	}
	if end < 0 {
		end = 0
	}
	return binarySearch(nums, 0, end, target) || binarySearch(nums, end+1, len(nums)-1, target)
}
