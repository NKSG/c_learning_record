//No.3
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 256;
        int last[ASCII_MAX];//纪录字符上次出现的位置
        fill(last,last+ASCII_MAX,-1);
        int len = 0, max_len = 0;
        for(size_t i=0; i< s.size();i++,len++){
            if(last[s[i]]>=0){
                max_len = max(len,max_len);
                len=0;
                i = last[s[i]]+1;
                fill(last,last+ASCII_MAX,-1);
            }
            last[s[i]] = i;
        }
        return max(len,max_len);
    }
};
