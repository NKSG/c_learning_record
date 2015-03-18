//No.27
//https://leetcode.com/problems/remove-element/
//Remove Element
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int index = 0;
        for(int i=0; i<n; i++){
            if(A[i]!=elem){
                A[index++] = A[i];
            }
        }
        return index;
    }

    int removeElement(int A[], int n, int elem) {
        return distance(A,remove(A,A+n,elem));
    }
};
