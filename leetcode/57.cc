//No.57
//https://leetcode.com/problems/insert-interval/
//Insert interval
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        while(it!=intervals.end()){
            if(newInterval.end < it->start){
                intervals.insert(it,newInterval);
                return intervals;
            }else if(newInterval.start > it->end){
                it++;
                continue;
            }else{
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);//返回指向下一个元素的指针
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comp1(const Interval &lhs, const Interval &rhs){
        return lhs.start<rhs.start;
}
bool comp2(const Interval &lhs, const Interval &rhs){
        return lhs.end<rhs.end;
}
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator begin = lower_bound(intervals.begin(),intervals.end(),newInterval,comp1);
        if(begin!=intervals.begin() && (begin-1)->end >= newInterval.start){
            --begin;
            newInterval.start = begin->start;
        }
        vector<Interval>::iterator end = lower_bound(intervals.begin(),intervals.end(),newInterval,comp2);
        if(end!=intervals.end() && end->start <= newInterval.end){
            newInterval.end = end->end;
            ++end;
        }
        vector<Interval>::iterator t = intervals.erase(begin,end);
        intervals.insert(t,newInterval);
        
        return intervals;
    }
};
