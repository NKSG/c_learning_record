//No.191
//https://leetcode.com/problems/number-of-1-bits/
//Number of 1 bits
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans;
        while(n){
            n &= n-1;
            ans++;
        }
        return ans;
    }
    
    int hammingWeight2(uint32_t n) {
        int i=0;
        int ans=0;
        while(i++<32){
            ans += n&1;
            n >>= 1;
        }
        return ans;
    }

};
