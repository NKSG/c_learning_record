//No.81
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
//Search in Rotated Sorted Array II

class Solution {
public:
    
/*
    bool isPossible(const int &A[], int start, int end, int key){
        if(A[start] == key || A[end] == key)
            return true;
        if(A[start]<A[end]){
            return (A[start]<key && key<A[end]);
        }else if(A[start]>A[end]){
            return (A[start]<key || key<A[end]);
        }else{
            return isPossible(A,start+1,end,key);
        }
    }
    
    bool search(int A[], int n, int target) {
        int left = 0;
        int right = n-1;
        int mid;
        while(left<=right){
            mid = (left+right)/2;
            if(A[mid]==target){
                return true;
            }
            else if(isPossible(A,left,mid,target)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return false;
    }
    */
    bool search(int A[],int n, int target){
        int left = 0, right = n-1, mid;
        while(left<=right){
            mid = (left+right)/2;
            if(A[mid]==target)
                return true;
            if(A[left]<A[mid]){
                if(A[left]<=target && target<A[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }else if(A[left]>A[mid]){
                if(A[mid]<target && target<=A[right])
                    left = mid+1;
                else
                    right = mid-1;
            }else{
                left++;
            }
        }
        return false;
    }

};


