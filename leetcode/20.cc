//No.20
//https://leetcode.com/problems/valid-parentheses/
//Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stack;
        
        for(auto c:s){
            if(left.find(c) != string::npos){
                stack.push(c);
            }else{
                if(stack.empty()||stack.top()!=left[right.find(c)])
                    return false;
                else
                    stack.pop();
            }
        }
        return stack.empty();
    }

    bool isValid(string s) {
        stack<char> stack;
        string::iterator it;
        for(it = s.begin(); it<s.end(); ++it){
            if((*it=='{')||(*it=='[')||(*it=='(')){
                stack.push(*it);
            }
            if((*it=='}')||(*it==']')||(*it==')')){
                if(stack.empty()||(stack.top()-*it>2))
                    return false;
                else
                    stack.pop();
            }
        }
        return stack.empty();
    }


};
