/*
  题目：
  给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> rst;
        if( A.empty() ){
            return rst;        
        }
    
        queue<int> odd;
        for(int i=0; i<A.size(); i++){
            if( A[i]%2==1 ){//奇数
                odd.push(A[i]);
            }else{//偶数
                rst.push_back(A[i]);
            }
        }
        
        while( !odd.empty() ){
            rst.push_back( odd.front() );                
            odd.pop();
        }
    
        return rst;    
    }
};
