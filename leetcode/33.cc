//No.33
//https://leetcode.com/problems/search-in-rotated-sorted-array/
//Search in Rotated Sorted Array 

class Solution {
public:
    bool isPossible(int start, int end, int key){
        if(start == key || end == key)
            return true;
        if(start<end){
            return (start<key && key<end);
        }else if(start>end){
            return (start<key || key<end);
        }else{
            return false;
        }
    }
    
    int search(int A[], int n, int target) {
        int left = 0;
        int right = n-1;
        int mid;
        while(left<=right){
            mid = (left+right)/2;
            if(A[mid]==target){
                return mid;
            }
            else if(isPossible(A[left],A[mid],target)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }
    
    int search(int A[], int n, int target){
        int left = 0, right = n-1, mid;
        while(left<=right){
            mid = (left+right)/2;
            if(A[mid]==target){
                return mid;
            }
            if(A[left] <= A[mid]){
                if(A[left]<=target && target<=A[mid])
                    right = mid;
                else
                    left = mid+1;
            }else{
                if(A[mid]<=target && target<=A[right])
                    left = mid+1;
                else
                    right = mid;
            }
        }
        return -1;
    }
};
