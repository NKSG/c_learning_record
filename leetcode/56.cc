//No.56
//https://leetcode.com/problems/merge-intervals/
//merge intervals

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
int cmp(const Interval &i1, const Interval &i2){
    if(i1.start == i2.start){
        return i1.end > i2.end;
    }else{
        return i1.start < i2.start;
    }
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if(intervals.size()<=1) return intervals;
        //借用std::sort来进行排序，但要注意cmp函数必须定义在solution外
        std::sort(intervals.begin(),intervals.end(),cmp);
        Interval start = intervals[0];
        int i=1;
        while(i<intervals.size()){
            if(intervals[i].end <= start.end){
                i++;
            }else if(intervals[i].start <= start.end){
                start.end = intervals[i].end;
                i++;
            }else{
                result.push_back(start);
                start = intervals[i];
            }
            
        }
        result.push_back(start);
        return result;
    }
};
