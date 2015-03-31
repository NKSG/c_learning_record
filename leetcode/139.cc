//No.139
//https://leetcode.com/problems/word-break/
//Word Break
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int j=1; j<=n; j++)
            for(int i=0; i<j; i++){
                if(dp[i]){
                    string str = s.substr(i,j-i);
                    if(dict.find(str) != dic.end()){
                        dp[j]=true;
                        break;
                    }
                }
            }
        return dp[n];
    }
};
