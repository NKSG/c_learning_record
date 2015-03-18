//No.70
//https://leetcode.com/problems/climbing-stairs/
//Climbing Stairs
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        if(n==2) return 2;
        int a = 1, b=2, c=2;
        for(int i=2; i<n; i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
