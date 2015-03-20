//No.7
//https://leetcode.com/problems/reverse-integer/
//Reverse Integer
class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        while(x){
            ans = x%10 + ans*10;
            x/=10;
        }
        return (ans<INT_MIN||ans>INT_MAX)?0:ans;
    }
};
