//No.88
//https://leetcode.com/problems/merge-sorted-array/
//Merge Sorted Array
class Solution {
public:
    void merge(int A[], int m, int B[], int n){
        int ai = m-1;
        int bi = n-1;
        int ti = m+n-1;
        while(ai>=0 && bi>=0){
            A[ti--] = A[ai]>B[bi] ? A[ai--]:B[bi--];
        }
        while(bi>=0){
            A[ti--] = B[bi--];
        }
    }
};
