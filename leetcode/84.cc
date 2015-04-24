//No.84
//https://leetcode.com/problems/largest-rectangle-in-histogram/
//Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int i=0;
        int maxArea = 0;
        stack<int> a;
        height.push_back(0);
        while(i<height.size()){
            if(a.empty()||height[a.top()]<=height[i]){
                a.push(i++);
            }else{
                int temp = a.top();
                a.pop();
                maxArea = max(maxArea,height[temp]*(a.isempty()?i:i-a.top()-1));
            }
        }
        return maxArea;
    }
};
