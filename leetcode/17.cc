//No.17
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//Letter Combinations of a Phone Number
//

class Solution {
public:
    const vector<string> keyboard{" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinations(string &digits) {
        vector<string> result;
        if(digits.empty()) return result;//加入以AC...
        dfs(digits,0,"",result);
        return result;
    }
    
    void dfs(const string &digits,size_t cur, string path, vector<string> &result){
        if(cur == digits.size()){
            result.push_back(path);
            return;
        }
        for(auto c : keyboard[digits[cur]-'0']){
            dfs(digits,cur+1,path+c,result);
        }
    }
};
