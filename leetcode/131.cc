//No.131
//https://leetcode.com/problems/palindrome-partitioning/
//Palindrome partitioning
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool> > dp(n,vector<bool>(n,false));
        for(int i=0; i<n; i++)
            dp[i][i]=true;
        for(int i=n-1; i>=0; i--)
            for(int j=i; j<n; j++){
                if(s[i]==s[j] && (i+1>j-1 || s[i+1][j-1]))
                    dp[i][j]=true;
            }
        vector<vector<string> > result;
        vector<string> path;
        print(s,0,dp,result,path);
        return move(result);
    }
    
    void print(string s, int start, vector<vector<bool> > &dp, vector<vector<string> > &result, vector<string> &path){
            if(start == s.length()){
                result.push_back(path);
                return;
            }
            for(int i=start; i<s.length(); ++i){
                if(dp[start][i]){
                    string sub = s.substr(start,i-start+1);
                    path.push_back(sub);
                    print(s,i+1,dp,result,path);
                    path.pop_back();
                }
            }
    }
};
