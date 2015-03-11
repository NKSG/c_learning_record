//No.26
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        int index = 0;
        for(int i=1; i<n; i++){
            if(A[index]!=A[i]){
                A[++index]=A[i];
            }
        }
        return index+1;
    }
};

    int removeDuplicates(int A[], int n){
        return distance(A,unique(A,A+n));
    }

    int removeDuplicates(int A[], int n){
        return removeDuplicates(A,A+n,A)-A;
    }
    
    template<typename InIt, typename OutIt>
    OutIt removeDuplicates(InIt first, InIt last, OutIt output){
        while(first!=last){//first<=last?
            *output++ = *first;
            first = upper_bound(first, last, *first);
        }
        return output;
    }
