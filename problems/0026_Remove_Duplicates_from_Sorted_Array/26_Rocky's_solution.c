/* ����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
 * ��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
 * ʾ�� 1:
 * �������� nums = [1,1,2], 

 * ����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2�� 

 * �㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
 * ʾ�� 2:
 * ���� nums = [0,0,1,1,1,2,2,3,3,4],

 * ����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��

 * �㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
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