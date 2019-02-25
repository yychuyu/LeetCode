class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if (flowerbed.size() == 0) return false;
        if (flowerbed.size() == 1 && flowerbed[0] == 0) return true;
        for (int i = 0; i < flowerbed.size() && n > 0; i++){
            if (flowerbed[i] == 0){
                if (i == 0 || i == flowerbed.size()-1) count++;
                count++;
            }else{
                n -= (count-1)/2;
                count = 0;
            }
        }
        n -= (count-1)/2;
        return n<=0;
    }
};
