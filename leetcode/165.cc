//No.165
//https://leetcode.com/problems/compare-version-numbers/
//Compare version numbers
//
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> result1 = getInt(version1);
        vector<int> result2 = getInt(version2);
        int len1 = result1.size();
        int len2 = result2.size();
        if(len2<len1) return -1*compareVersion(version2,version1);
        int i=0;
        while(i<len1 && result1[i]==result2[i]) i++;
        if(i==len1){
            int j=len2-1;
            while(j>=len1){
                if(result2[j--]!=0)
                    return -1;
            }
            return 0;
        }else{
            if(result1[i]<result2[i])
                return -1;
            else return 1;
        }
    }
private:
    vector<int> getInt(string value){
        vector<int> result;
        int len = value.size();
        int pre = 0;
        for(int i = 0 ; i<len; i++){
            if(value[i]=='.'){
                string str(value.begin()+pre,value.begin()+i);
                result.push_back(stoi(str));
                pre = i+1;
            }
        }
        string str(value.begin()+pre,value.end());
        result.push_back(stoi(str));
        return result;
    }
};

