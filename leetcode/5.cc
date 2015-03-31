//No.5
//https://leetcode.com/problems/longest-palindromic-substring/
//Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1) return s;
        int start = 0;
        int maxLen = 1;
        for(int i=0; i<n; i++){
            int left = i;
            int right = i;
            while(right+1<n && s[right+1]==s[left])
                ++right;
            i = right;
            while(left-1>=0 && right+1<n && s[left-1]==s[right+1])
                --left,++right;
            int len = right -left +1;
            if(len>maxLen)
                start = left, maxLen = len;
        }
        return s.substr(start,maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1) return s;
        int start = 0;
        int maxLen =1;
        bool dp[1000][1000]={false};
        for(int i=0; i<n; i++)
            dp[i][i] = true;
        for(int i=1; i<n; i++)
            for(int j=0; j<i; j++){
                if(s[i]==s[j] && (j+1>i-1||dp[j+1][i-1])){
                    dp[j][i]=true;
                    int len = i-j+1;
                    if(len>maxLen)
                        maxLen = len, start = j;
                }
            }
        return s.substr(start, maxLen);
        }
};
