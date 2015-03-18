//No.49
//https://leetcode.com/problems/anagrams/
//Anagrams
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > sortedKeyValue;
        for(int i=0; i<strs.size(); i++){
            string tmp = strs[i];
            std::sort(tmp.begin(),tmp.end());
            sortedKeyValue[tmp].push_back(strs[i]);
        }
        vector<string> result;
        auto it = sortedKeyValue.begin();
        for(;it!=sortedKeyValue.end();it++){
            if((*it).second.size()<=1) continue;
            std::copy((*it).second.begin(),(*it).second.end(),back_inserter(result));
        }
        return move(result);
    }
};
