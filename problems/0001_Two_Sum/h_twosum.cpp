class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int temp;
	vector<int> result(2, 1);
	int num = nums.size();
	for(int i = 0; i < num; i++){
		for(int j = i + 1; j < num; j++){
			temp = target - nums[i];
			if(temp == nums[j]){		
				result[0] = i;
				result[1] = j;
				return result;
			} 
		}
	}
	return result;    
    }
};
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> twoSum (vector<int>& nums, int target){
//	int temp;
//	vector<int> result(2, 1);
//	int num = nums.size();
//	for(int i = 0; i < num; i++){
//		for(int j = i + 1; j < num; j++){
//			temp = target - nums[i];
//			if(temp == nums[j]){		
//				result[0] = i;
//				result[1] = j;
//				return result;
//			} 
//		}
//	}
//	return result;
//}
//
//
//int main(){
//	
////	vector<int> test(2, 0);
//	vector<int> nums(4, 0);
//	for(int i = 0; i < 4; i++){
//		cin >> nums[i];
//	}
//	
//	int target;
//	cin >> target;
//
//	test = twoSum (nums, target);	
////	cout << test[0] << test[1] << endl;
//	return 0;
//} 


//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, int> m;
//        vector<int> res;
//        for (int i = 0; i < nums.size(); ++i) {
//            m[nums[i]] = i;
//        }
//        for (int i = 0; i < nums.size(); ++i) {
//            int t = target - nums[i];
//            if (m.count(t) && m[t] != i) {
//                res.push_back(i);
//                res.push_back(m[t]);
//                break;
//            }
//        }
//        return res;
//    }
//};



