//No.97
//https://leetcode.com/problems/interleaving-string/
//Interleaving String
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        
        if(n1+n2!=n3) return false;
        if(n1==0) return s2==s3;
        if(n2==0) return s1==s3;
        
        vector<vector<bool> > dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n1; i++)
            dp[i][0] = (s1[i-1]==s3[i-1]);
        for(int i=1; i<=n2; i++)
            dp[0][i] = (s2[i-1]==s3[i-1]);
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++){
                if(s1[i-1]==s3[i+j-1] && dp[i-1][j])
                    dp[i][j] = true;
                else if(s2[j-1]==s3[i+j-1] && dp[i][j-1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        return dp[n1][n2];
    }
};
