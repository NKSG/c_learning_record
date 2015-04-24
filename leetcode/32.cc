//No.32
//https://leetcode.com/problems/longest-valid-parentheses/
//Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int max_len = 0;
        int last = -1;
        for(auto i=0; i<s.size(); ++i){
            if(s[i]=='('){
                stack.push(i);
            }else if(s[i]==')'){
                if(stack.empty()){
                    last = i;
                }else{
                    stack.pop();
                    if(stack.empty()){
                        max_len = max(max_len,i-last);
                    }else{
                        max_len = max(max_len, i-stack.top());
                    }
                    
                }
            }
        }
        return max_len;
    }
};
