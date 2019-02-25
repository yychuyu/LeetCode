#include <string>
#include <vector>
#include <iostream>
using namespace std;
// using std::vector;

class Solution
{
  public:
    int len1,len2;
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {    
        if(nums1.size()>=nums2.size()){
            len1=nums1.size();
            len2=nums2.size();
            return findM(nums1,nums2);
        }
        else{
            len2=nums1.size();
            len1=nums2.size();
            return findM(nums2,nums1);
        }
        


    }
    double findM(vector<int> &nums1, vector<int> &nums2){
        int l1=0,l2=0,r1=(len1-1>0)?len1-1:0,r2=(len2-1)?len2-1:0;
        int p1,p2;     
        while (true){
            p1=(l1+r1)/2;
            p2=(len1+len2-1)/2-p1;   
            // cout<<l1<<l2<<r1<<r2<<endl;
            if(l1==r1 || l2 ==r2 || len1==0 || len2==0) break;
            if (nums1[p1]>nums2[p2]){
                if(l1==p1)
                r2=p2-1;
                else{
                    r1=p1;
                    l2=p2;
                }
            }
            else if(nums1[p1]==nums2[p2]){
                l1=l2=p1;
                r1=r2=p2;
            }
            else {
              if(l1==p1)
                l1=r1;
              else {
                  l1=p1;
                  r2=p2;
              }
            }
        }
        if (len1==0) {
            if ((len1+len2)%2 ) return (double) nums2[p2];
            else return (double) (nums2[p2]+nums2[p2+1])/2;
        }
        else if (len2==0){
            if ((len1+len2)%2 ) return (double) nums1[p1];
            else return (double) (nums1[p2]+nums1[p2+1])/2;
        }
        else if (l1==r1 && l2==r2){
            if ((len1+len2)%2 ) return nums1[l1]>=nums2[l2]?(double) nums1[l1]:(double) nums2[l2];
            else return (double) (nums1[l1]+nums2[l2])/2;
        }
        else if(l1==r1){
            if ((len1+len2)%2) 
             { 
                 if(nums1[l1]<nums2[p2]) return (double) nums2[p2];
                 if (nums1[l1]<=nums2[p2+1]) return  (double) nums1[l1];
             return  nums2[p2+1];
             }
            else return nums1[l1]>=nums2[p2+1] ?(double) (nums2[p2]+nums2[p2+1])/2 :(double) (nums2[p2]+nums1[l1])/2;
        }
        else{
            if ((len1+len2)%2){
                if(nums2[l2]<nums1[p1]) return (double) nums1[p1];
                if(nums2[l2]<=nums1[p1+1]) return (double) nums2[l2];
                return nums1[p1+1];
            } 
            // return nums2[l2]>=nums1[p1] ?(double) nums2[l2]:(double) nums1[p1];
            else  return nums2[l2]>=nums1[p1+1] ?(double) (nums1[p1]+nums1[p1+1])/2 :(double) (nums1[p1]+nums2[l2])/2;
        }
    }
        
};

int main()
{
    int a[1] = {1};
    int b[2] = {2,3};
    //通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
    vector<int> nums1(a,a+1);

    vector<int> nums2(b, b + 2);

    double ret = Solution().findMedianSortedArrays(nums1, nums2);

    string out = to_string(ret);

    return 0;
}