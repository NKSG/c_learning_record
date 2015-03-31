//No.76
//https://leetcode.com/problems/minimum-window-substring/
//Minimum Window Substring
class Solution {
public:
    string minWindow(string S, string T) {
        string str = "";
        int lenS = static_cast<int>(S.size());
        int lenT = static_cast<int>(T.size());
        if(lenT == 0) return str;
        
        int minLen = lenS+1;
        int num[256]{};
        int count[256]{};
        
        for(int index = 0; index<static_cast<int>(T.size()); index++){
            num[static_cast<int>(T[index])]++;
        }
        int first = 0, second = 0;
        int chaCount = 0;
        while(second<lenS){
            int secCha = (int)S[second];
            if(++count[secCha]<=num[secCha]){
                chaCount++;
            }
            if(chaCount == lenT){
                while(first<=second){
                    int firCha = (int)S[first];
                    if(count[firCha]>num[firCha])
                        count[firCha]--, first++;
                    else break;        
                }
                if(minLen>second-first+1){
                    minLen = second-first+1;
                    str = S.substr(first,minLen);
                }
            }
            second++;
        }
        return str;
    }
};
