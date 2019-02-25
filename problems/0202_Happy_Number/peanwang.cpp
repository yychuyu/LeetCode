class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> show;
        while(true){
            int result = 0;
            while(n){
                result +=(n%10)*(n%10);
                n/=10;
            }
            if(result==1)
                return true;
            else{
                if(show.find(result) !=show.end())
                    break;
                else
                    show[result]=true;
            }
            n = result;
        }
        return false;
    }
};