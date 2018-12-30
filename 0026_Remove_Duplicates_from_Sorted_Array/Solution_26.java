class Solution {
    public int removeDuplicates(int[] nums) {
    //如果数组长度为0，直接返回
    if(nums.length==0)return 0;
    int i=0;
    for(int n:nums){
    //因为数组已经排序过了，所以判断是否大于前一个即可
        if(i==0||n>nums[i-1])
            nums[i++]=n;
    }
    return i;
}
}