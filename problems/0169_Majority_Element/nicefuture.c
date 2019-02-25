int majorityElement(int* nums, int numsSize) {
    //--> appears more than n/2 times  利用这一特点
    int num = nums[0], cnt = 1;
    for (int i = 1; i < numsSize; i++) {
        if (num == nums[i]) cnt++;
        else cnt--;
        if (cnt == 0) {
            num = nums[i];
            cnt = 1;
        }
    }
    return num;
}

/* c++解法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map 映射法
        map<int, int> cnt;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
            if (!cnt.count(*i)) cnt[*i] = 0;
            cnt[*i]++;
        }
        for (map<int, int>::iterator i = cnt.begin(); i != cnt.end(); i++) {
            if (i->second > nums.size()/2) return i->first;
        }
        return -1;
    }
};
*/

/* 先排序再遍历，粗暴，慢
void quickSort(int *nums, int lower, int ceiling) {
    if (ceiling-lower <= 1) return;
    int i = lower, j = ceiling;
    int temp = nums[i];
    while (i < j) {
        while (i < j && nums[j] >= temp) j--;
        if (i < j) nums[i] = nums[j];
        while (i < j && nums[i] < temp) i++;
        if (i < j) nums[j] = nums[i];
    }
    nums[i] = temp;
    quickSort(nums, lower, i-1);
    quickSort(nums, i+1, ceiling);
}

int majorityElement(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize-1);
    
    int num = 0, len = 0, cnt_num = nums[0], cnt = 1;
    
//     for (int i = 0; i < numsSize; i++) {
//         printf("%d ", nums[i]);
//     }
//     putchar('\n');
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == cnt_num) {
            cnt++;
        } else {
            if (cnt > len) {
                len = cnt;
                num = cnt_num;
            }
            cnt_num = nums[i];
            cnt = 1;
        }
    }
    if (cnt > len) {
        len = cnt;
        num = cnt_num;
    }
    return num;
}
*/
