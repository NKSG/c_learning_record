//No.154
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
//Find Minimum in Rotated Sorted Array II
class Solution {
public:
    int findMin(vector<int> &num) {
        for(int i=1; i<num.size(); i++){
            if(num[i]<num[i-1])
                return num[i];
        }
        return num[0];
    }

/*    int findMin(vector<int> &num){
        assert(num.size()!=0);
        if(num.size()==1) return num[0];
        int result = INT_MAX;
        int left = 0, right = num.size()-1;
        while(left<=right){
            int mid = left+((right-left)>>1);
            if(num[mid]<num[right]){
                result = std::min(result,num[mid]);
                right = mid-1;
            }else if(num[left]<=num[mid]){
                result = std::min(result,num[left]);
                left = mid+1;
            }else{
                result = std::min(result,num[mid]);
                right = mid-1;
            }
        }
        return result;
    }
*/
};
