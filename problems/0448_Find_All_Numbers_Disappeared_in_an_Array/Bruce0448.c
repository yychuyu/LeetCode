# solution Two
# others：《Find All Numbers Disappeared in an Array》，顺便简单解释一下友题《Find All Duplicates in an Array》。
#          此解法三，也是Solution one 的C实现。
# url：https://blog.csdn.net/yutianzuijin/article/details/53861485

void swap(int *a, int *b){
    int temp = *a;
	*a = *b;
	*b = temp;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int)*numsSize)；
	
	for(int i = 0; i<numsSize; i){
		while(nums[i]!=i+1&&nums[nums[i]-1]!=nums[i])		{
			swap(&nums[i],&nums[nums[i]-1]);
		}
	}

	*returnSize = 0;
	
	for(int i=0; i<numsSize; i++){
		if(nums[i]!=i+1){
			result[*returnSize]=i+1;
			*returnSize=*returnSize+1;
		}
	}
	
	return result;
}

####################
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

	