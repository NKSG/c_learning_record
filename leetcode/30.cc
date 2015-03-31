//No.30
//https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        size_t wordLength = L.front().length();
        size_t catLength = wordLength*L.size();
        vector<int> result;
        
        if(S.length()<catLength) return result;
        unordered_map<string,int> wordCount;
        for(auto const &word: L) ++wordCount[word];
        for(auto i = begin(S); i<=prev(end(S),catLength); ++i){
            unordered_map<string, int> unused(wordCount);
            for(auto j=i; j!=next(i,catLength); j+=wordLength){
                auto pos = unused.find(string(j,next(j,wordLength)));
                if(pos==unused.end()||pos->second==0) break;
                if(--pos->second == 0) unused.erase(pos);
            }
            if(unused.size()==0) result.push_back(distance(begin(S),i));
        }
        return result;
    }
};
