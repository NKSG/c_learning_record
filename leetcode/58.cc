//No.58
//https://leetcode.com/problems/length-of-last-word/
//Length of Last Word 
//
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        while(*s){
            if(*s++!=' '){
                ++length;
            }else if(*s && *s!=' '){//此时的条件有,*s在上一个判断中为空格，现在即*(s+1)存在且有值
                length = 0;
            }
        }
        return length;
    }
};
