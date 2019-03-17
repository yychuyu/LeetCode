# 这个链接很实在
# 寻找给定元素在数组中的位置，如果没有此元素的话给出插入的位置
# https://blog.csdn.net/yinyanting1/article/details/56672961


# Solution One
public int searchInsert(int[] nums, int target){
	for(int i = 0; i < nums.length; i++){
		if(nums[i] == target || nums[i] > target)
			return i;
	}
	return nums.length;
}









public int searchInsert(int[] A, int target){
	int low = 0, high = A.length-1;
	while(low <= high){
		int mid = (low + high)/2;
		if(A[mid] == target) return mid;
		else if(A[mid] > target) high = mid -1;
		else low = mid + 1;
	}
	return low;
}



