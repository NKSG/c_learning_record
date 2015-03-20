//No.71
//https://leetcode.com/problems/simplify-path/
//Simplify Path 
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        for(auto i = path.begin(); i!= path.end();){
            ++i;//为了不搜第一个/
            auto j=find(i,path.end(),'/');
            auto dir = string(i,j);
            if(!dir.empty() && dir !="."){
                if(dir==".."){
                    if(!dirs.empty())
                        dirs.pop_back();
                }else
                    dirs.push_back(dir);
            }
            i=j;
        }
        stringstream out;
        if(dirs.empty()){
            out<<"/";
        }else{
            for(auto dir:dirs)
                out<<'/'<<dir;
        }
        return out.str();
    }
};
