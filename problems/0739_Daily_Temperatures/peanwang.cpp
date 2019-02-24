/*************************
**solution1:             *
**time complexity: O(N^2)*
**************************
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> warmer(T.size());
        for(int i=0;i<T.size()-1;i++){
            for(int j=i+1;j<T.size();j++){
                if(T[i] < T[j]){
                    warmer[i] = j-i;
                    break;
                }
            }
        }
        return warmer;
    }
};
/*************************
**solution2:             *
**time complexity: O(N)  *
**************************
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> warmer(T.size());
        stack<int> S;
        for(int i = T.size()-1;i>=0;i--){
            while(!S.empty() && T[S.top()] <=T[i]) S.pop();
            warmer[i] = S.empty()?0:S.top()-i;
            S.push(i);
        }
        return warmer;
    }
};