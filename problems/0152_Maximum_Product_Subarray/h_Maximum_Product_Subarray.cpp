class Solution {
public:
    int maxProduct(vector<int>& nums) {
	int res = nums[0];
	int temp;
        
	for(int i = 0; i < nums.size(); i++){   
           temp = nums[i];
		for(int j = i+1; j < nums.size(); j++){
			temp = temp*nums[j];	
            if(res < temp)
			res = temp;
		}
	} 
        
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > res)
            res = nums[i];
    }  
	return res;   
    }
};


//#include <iostream>
//#include <vector>
//using namespace std;
// 
//int maxProduct(vector<int>& nums) {
////    map<int, int>  m;
//	int res = nums[0];
//	int temp;
//	for(int i = 0; i < nums.size(); i++){      
//		for(int j = i; j < nums.size(); j++){
//			if(i = j){
//				temp = nums[i];
//			}else
//			temp = nums[i]*nums[j];			
//			if(res < temp)
//			res = temp;
//		}
//	} 
//	return res; 
//}
//    
//int main(){
//	return 0;
//}
