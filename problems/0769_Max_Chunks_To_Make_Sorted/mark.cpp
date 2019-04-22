// 我们只要维护一个数组max[]，max[i]表示输入数字arr[0...i]这个区间最大的值。因为这个输入数组包含所有0到n-1的数字，所以我们只需要从左到右来判断是否max[i] == i，如果满足就说明了小于等于i的数都在包含了，这里可以是所谓chunk的一个分割点

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int num = 0;
        int max = arr[0];
        int len = arr.size();
        for(int i = 0; i < len; i++){
            max = arr[i] > max ? arr[i] : max;
            if (max == i)
                num++;
        }
        
        return num;
    }
    
};

