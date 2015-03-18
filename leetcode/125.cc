//No.125
//https://leetcode.com/problems/valid-palindrome/
//Valid Palindrome

class Solution {
public:
    /*
    bool isPalindrome(string s) {
        string s2;
        string::iterator it;
        for(it = s.begin();it<s.end();++it){
            if(*it-'a'>=0 && 'z'-*it>=0)
                s2+=*it;
            if(*it-'A'>0 && 'Z'-*it>=0)
                s2+=char(*it-'A'+'a');
        }
        string::iterator it2=s2.begin();
        string::iterator it3=prev(s2.end());
        while(it2<it3){
            if(*it2!=*it3)
                return false;
            it2++;
            it3--;
        }
        return true;
    }
    */

    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        auto left = s.begin(), right= prev(s.end());
        while(left<right){
            if(!::isalnum(*left)) ++left;
            else if(!::isalnum(*right)) --right;
            else if(*left != *right) return false;
            else{
                ++left;
                --right;
            }
        }
        return true;
    }


};
