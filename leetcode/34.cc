//No.34
//https://leetcode.com/problems/search-for-a-range/
//search for a range
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        const int l = distance(A,lower_bound(A,A+n,target));
        const int u = distance(A,prev(upper_bound(A,A+n,target)));
        if(A[l]!=target){
            return vector<int> {-1,-1};
        }else{
            return vector<int> {l,u};
        }
    }
    
    int lower(int *A, int n, int tareget){
        int left = 0;
        int right = n;
        while(left!=right){
            int mid = (left+right)/2;
            if(A[mid]<target)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }

    int upper(int *A, int n, int target){
        int left = 0;
        int right = n;
        while(left!=right){
            int mid = (left+right)/2;
            if(A[mid]<=target)
                left = mid+1;
            else
                right = mid;
        }
        return left
    }

    vector<int> searchRange(int A[], int n, int target){
        assert(A!=NULL && n!=0);
        int left = lower(A,n,target);
        int right = upper(A,nmtarget);
        if(left == n || A[left]!=target)
            return vector<int>(2,-1);
        return vector<int>{left,right-1};
    }

};

