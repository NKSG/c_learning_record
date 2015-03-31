//No.53
//https://leetcode.com/problems/maximum-subarray/
//Maximum Subarray
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max_so_far = A[0];
        int max_end_here = A[0];
        for(int i=1; i<n; i++){
            if(max_end_here<0)
                max_end_here = A[i];
            else
                max_end_here += A[i];
            max_so_far = max(max_so_far, max_end_here);
        }
        return max_so_far;
    }
};

