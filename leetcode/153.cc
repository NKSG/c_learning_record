//No.153
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
//Find Minimum in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int> &num) {
        for(int i=1; i<num.size(); i++){
            if(num[i]<num[i-1])
                return num[i];
        }
        return num[0];
    }
};
