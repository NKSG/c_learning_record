//No.169
//https://leetcode.com/problems/majority-element/
//Majority Element
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        if(n==0) return -1;
        sort(num.begin(),num.end());
        return num[n/2];
    }
};
