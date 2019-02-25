//32ms
/*
  题目：
  给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if( A.empty() ){
            return vector<int>{};
        }
        
        int front=0;
        int rear=A.size()-1;
        while( front!=rear ){
            if( A[front]%2==0 ){
                front++;
                continue;
            }
            if( A[rear]%2==1 ){
                rear--;
                continue;
            }
            //至此，A[front]为奇数，A[rear]为偶数，需要互换。
            swap(A[front], A[rear]);
        }
        
        return A;        
    }
};
