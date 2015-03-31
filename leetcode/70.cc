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

//0325
int climbStairs(int n){
    if(n<=1) return n;
    if(n==2) return 2;
    return climbStairs(n-1)+climbStairs(n-2);
}

int climbStairs(int n){
    int dp[n+1]{};
    if(n>0 && n<=2) return n;
    if(dp[n]!=0) return dp[n];
    dp[n] = climbStairs(n-1)+climbStairs(n-2);
    return dp[n];
}


int climbStairs(int n){
    if(n<=2) return n;
    int f[n+1]{};
    f[1]=1;
    f[2]=2;
    for(int i=2; i<n; ++i){
        f[i]=f[i-1]+f[i-2];
        //不缓存的话
        //c=a+b;
        //a=b;
        //b=c;
    }
    return f[i];
}
