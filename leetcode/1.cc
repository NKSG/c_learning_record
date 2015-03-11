//No.1
//https://leetcode.com/problems/two-sum/
//Two sum
class Solution{
public:
/*
 * Runtime Error O(n^2)
    vector<int> twoSum(vector<int> &numbers, int target){
        vector<int> ans;
        for(int i = 0; i<numbers.size(); ++i){
            int num_1 = numbers[i];
            int num_2 = target - num_1;
            for(int j=1;j<numbers.size();++j){
                if(numbers[j]==num_2){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    return ans;
                }
            }
        }
        return;
    }
//O(n),O(n)
//存在问题，eg.[3,2,4] 6;
//输出1,1 重复
    vector<int> twoSum(vector<int> &numbers, int target){
        unordered_map<int,int> mapping;
        vector<int> result;
        for(int i=0; i<numbers.size(); ++i){
            mapping[numbers[i]]=i;
        }
        for(int i=0; i<numbers.size(); ++i){
            const int gap = target-numbers[i];
            if(mapping.find(gap)!=mapping.end()){
                result.push_back(i+1);
                result.push_back(mapping[gap]+1);
                break;
            }
        }
        return result;
    }*/
//
//O(n),O(n)
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> mapping;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            const int gap = target-numbers[i];
            if(mapping.find(gap)!=mapping.end()){
                result.push_back(mapping[gap]+1);
                result.push_back(i+1);
                return result;
            }
            mapping[numbers[i]]=i;
        }
        return result;
    }

};


