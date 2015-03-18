//No.28
//https://leetcode.com/problems/implement-strstr/
//Implement strstr()
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int index = -1;
        char *head = haystack;
        int tokenLen = strlen(needle);
        while(strlen(head)>=tokenLen){
            if(memcmp(head,needle,tokenLen)==0){
                index = head-haystack;
                break;
            }
            head++;
        }
        return index;
    }
};
