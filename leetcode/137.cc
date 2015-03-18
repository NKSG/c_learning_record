//No.137
//https://leetcode.com/problems/single-number-ii/
//Single Number 2
class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32] = {0};
        for(int i=0; i<n; i++){
            for(int j=0; j<32; j++){
                if(A[i]&(1<<j))
                    count[j] = (count[j]+1)%3;
            }
        }
        int r=0;
        for(int i=0; i<32; i++){
            if(count[i] !=0 )
                r|=(1<<i);
        }
        return r;    
    }
};
