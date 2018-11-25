class Solution {
public:
    int hammingWeight(uint32_t n) {
        const int array[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
        int count=0;
        uint32_t m = n>>16;
        for(int i=0;i<4;i++){
            count += array[(n & 0xf)];
            count += array[(m & 0xf)];
            n = n>>4;
            m = m>>4;
            if(n == 0 && m==0)
                break;
        }
        return count;
    }
};