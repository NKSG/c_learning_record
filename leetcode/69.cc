//No.69
//https://leetcode.com/problems/sqrtx/
//Sqrt(x)
class Solution {
public:
//TLE
    /*
    int sqrt(int x) {
        int answer=0;
        while(answer*answer<x)
            ++answer;
        if(answer*answer == x)
            return answer;
        else
            return -1;
    }
*/
    int sqrt(int x){
        int left = 1, int right = x/2;
        int mid;
        int last_mid;
        if(x<2) return x;
        while(left<=right){
            mid = left+(right-left)/2;
            if(x/mid>mid){
                left = mid+1;
                last_mid = mid;
            }else if(x/mid<mid){
                right = mid-1;
            }else{
                return mid;
            }
        }
        return last_mid;
    }
};
