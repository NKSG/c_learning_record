//No.152
//https://leetcode.com/problems/maximum-product-subarray/
//Maximum product subarray
class Solution {
public:
    int maxProduct(int A[], int n) {
        assert(A!=NULL && n!=0);
        int maxherepre = A[0];
        int minherepre = A[0];
        int maxsofar = A[0];
        int maxhere = 0;
        int minhere = 0;
        
        for(int i=1; i<n; i++){
            maxhere = max(max(maxherepre*A[i],minherepre*A[i]),A[i]);
            minhere = min(min(maxherepre*A[i],minherepre*A[i]),A[i]);
            maxsofar = max(maxhere, maxsofar);
            maxherepre = maxhere;
            minherepre = minhere;
        }
    return maxsofar;
    }
};
