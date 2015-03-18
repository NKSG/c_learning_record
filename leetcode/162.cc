//No/162
//https://leetcode.com/problems/find-peak-element/
//find peak element
class Solution {
public:
    
     int findPeakElement(const vector<int> &num) {
        if(num.empty()) return -1;
        if(num.size()==1) return 0;
        int i=1;
        for(; i<num.size(); i++){
            if(num[i]<num[i-1])
                return i-1;
        }
        return i-1;
    }
    

    int findPeakElement(const vector<int> &num){
        for(int i=1; i<num.size(); i++){
            if(num[i]<num[i-1])
            {
                return i-1;
            }
        }
        return num.size()-1;
    }    

    int findPeakElement(const vector<int> &num){
        int low = 0;
        int high = num.size()-1;
        while(low<high){
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1]<num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};
