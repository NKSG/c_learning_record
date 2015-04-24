//No.10
//https://leetcode.com/problems/regular-expression-matching/
//Regular Expression Matching

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p=='\0') return *s=='\0';
        
        if(*(p+1)!='*'){
            if(*p==*s||(*p=='.' && *s!='\0'))
                return isMatch(s+1,p+1);
            else
                return false;
        }else{
            while(*p==*s||(*p=='.' && *s!='\0')){
                if(isMatch(s,p+2))//之后还匹配
                    return true;
                s++;//之后可算不匹配了，s进1
            }
            return isMatch(s,p+2);
        }
    }
};
