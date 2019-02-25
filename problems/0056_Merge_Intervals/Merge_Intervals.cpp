/*
  题目：
  给出一个区间的集合，请合并所有重叠的区间。
  
  示例:
  输入: [[1,3],[2,6],[8,10],[15,18]]
  输出: [[1,6],[8,10],[15,18]]
  解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
  
  参考
  https://www.cnblogs.com/wangxiaobao/p/5823947.html
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval& i1, Interval& i2){
        return i1.start<i2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> rst;
        if( intervals.empty() ){
            return rst;
        }
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int s=intervals[0].start;
        int e=intervals[0].end;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start<=e){
                e=max(e,intervals[i].end);
            }else{
                rst.push_back( Interval(s,e) );
                s=intervals[i].start;
                e=intervals[i].end;
            }        
        }    
        rst.push_back( Interval(s,e) );
        
        return rst;
    }
};
