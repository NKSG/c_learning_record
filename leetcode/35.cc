//No.35
//https://leetcode.com/problems/search-insert-position/
//Search Insert Position
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        //assert(A != NULL && n!=0)
        int left = 0, right = n,mid;
        while(left!=right){
            mid = (left+right)/2;
            if(A[mid]>=target)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }

    int searchInsert(int A[], int n, int target){
        return lower_bound(A,A+n,target)-A;
        //return distance(A,lower_bound(A,A+n,target));
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value){
        while(first!=last){
            auto mid = next(first,distance(first,last)/2);
            if(value>*mid)
                first = ++mid;
            else
                last = mid;
        }
        return first;
    }


};
