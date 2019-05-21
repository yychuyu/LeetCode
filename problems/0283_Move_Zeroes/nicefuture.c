// 参考评论区，将非零值依次覆盖数组，末尾补零
void moveZeroes(int* nums, int numsSize){
    int position = 0;
    for (int i=0; i<numsSize; i++) {
        if (nums[i] != 0) nums[position++] = nums[i];
    }
    while (position < numsSize) {
        nums[position++] = 0;
    }
}

// 双层遍历，耗时更长
void moveZeroes(int* nums, int numsSize){
    int i = 0, cnt = 0;
    while (i < numsSize-cnt) {
        if (nums[i] != 0) i++;
        else {
            for (int j=i; j+1<numsSize-cnt; j++) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
            cnt++;
        }
    }
}


