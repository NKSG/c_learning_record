//No.11
//https://leetcode.com/problems/container-with-most-water/
//Container with most water

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        for(size_t i=1; i<height.size(); i++){
            for(size_t j=0; j<i;j++){
                int tempArea = (i-j)*min(height[i],height[j]);
                maxArea = max(tempArea,maxArea);
            }
        }
        return maxArea;
    }
};
//time limit exceeded

class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size()-1;
        int result = INT_MIN;
        while(start<end){
            int area = min(height[end],height[start])*(end-start);
            result = max(result,area);
            if(height[start]<=height[end]){
                start++;
            }else{
                end--;
            }
        }
        return result;
    }
};

//从两边向中间来搞就没问题...确实第一种思路有好多重复判断...
