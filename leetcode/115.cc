//No.115
//https://leetcode.com/problems/distinct-subsequences/
//Distinct Subsequences
class Solution {
public:
    int numDistinct(string S, string T) {
        int m = T.length();
        int n = S.length();
        if(m>=n) return T==S;
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<=n; ++i)
            dp[0][i]=1;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                dp[j][i] = dp[j][i-1]+(S[i-1]==T[j-1]?dp[j-1][i-1]:0);
        return dp[m][n];
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        int m = T.length();
        int n = S.length();
        if(m>n) return 0;
        
        vector<int> path(m+1, 0);
        path[0] = 1;
        for(int j=1; j<=n; j++){
            for(int i=m; i>=1; i--){
                path[i]=path[i]+(T[i-1]==S[j-1]?path[i-1]:0);
            }
        }
        return path[m];
    }
};
