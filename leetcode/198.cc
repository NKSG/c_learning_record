//No.198
//https://leetcode.com/problems/house-robber/
//House Robber
class Solution {
public:
    int rob(vector<int> &num) {
        int prevF=0, prevG=0, f=0, g=0;
        for(int i=num.size()-1; i>=0; i--){
            f = num[i]+prevG;
            g = max(prevF,prevG);
            prevF = f;
            prevG = g;
        }
        return max(f,g);
    }
};
