//No.172
//https://leetcode.com/problems/factorial-trailing-zeroes/
//factorial_trailing_zeroes
class Solution{
public:
    int trailingZeroes(int n){
        int ans = 0;
        while(n){
            n /= 5;
            ans += n;
        }
        return ans;
    }

    int trailingZeroes2(int n){
        if(n>4)
            return n/5+trailingZeroes(n/5);
        else
            return 0;
    }

};


