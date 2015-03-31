//No.120
//https://leetcode.com/problems/triangle/
//Triangle
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m=triangle.size();
        if(m==0) return 0;
        vector<int> dp(triangle[m-1]);
        for(int r=m-2; r>=0; r--)
            for(int c=0; c<=r; c++)
                dp[c] = min(dp[c],dp[c+1]+triangle[r][c]);
        return dp[0];
    }
};
