bool increasingTriplet(int* nums, int numsSize) {
	int a = INT_MAX, b = INT_MAX;
	int n = 0;
	while(n < numsSize)
	{
		if(nums[n] > b)
			return true;
		else if(nums[n] > a)
			b = nums[n];
		else
			a = nums[n];
		n++;
	}
	return false;
}