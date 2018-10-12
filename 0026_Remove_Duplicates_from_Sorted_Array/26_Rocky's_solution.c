/* 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 * 示例 1:
 * 给定数组 nums = [1,1,2], 

 * 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

 * 你不需要考虑数组中超出新长度后面的元素。
 * 示例 2:
 * 给定 nums = [0,0,1,1,1,2,2,3,3,4],

 * 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

 * 你不需要考虑数组中超出新长度后面的元素。
 */

#include <stdio.h>
 
int removeDuplicates(int* nums, int numsSize) {
    int *idx;
    idx = nums + 1;
    int count = numsSize;
	int i;
	
    for (i = 0; i < numsSize - 1; i++) {
        if (*idx == *nums) {
            idx++;
            count--;
        }
        else {
            *++nums = *idx;
            idx++;
        }
    }
    return count;
}

int main(void) {
	int input[] = {1, 1, 1, 2, 2, 2, 3, 4, 5, 8, 8};
	int length;
	int i;
	
	length = removeDuplicates(input, sizeof(input) / sizeof(int));

	for (i = 0; i < length; i++) {
		printf("%d\n", input[i]);
	}
	
	system("pause");
	return 0;
}