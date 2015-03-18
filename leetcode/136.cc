//No.136
//https://leetcode.com/problems/single-number/
//Single Number
class Solution {
public:
    int singleNumber(int A[], int n) {
        assert(n!=0);
        int r=A[0];
        for(int i=1; i<n; i++)
            r ^= A[i];
        return r;
    }

    int singleNumber(int A[], int n){
        unordered_map<int,int> count;
        for(int i=0; i<n; i++)
                count[A[i]]++;
        for(int i=0; i<n; i++){
            if(count[A[i]]!=2)
                return A[i];
        }
        return 0;
    }
};
