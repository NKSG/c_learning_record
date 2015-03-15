//No.75
//https://leetcode.com/problems/sort-colors/
//Sort Colors
class Solution {
public:
    void sortColors(int A[], int n) {
        if(n<=1) return ;
        int zero = 0, two = n-1;
        int i = 0;
        while(i<=two){
            if(A[i]==0){
                swap(A[i++],A[zero++]);
            }else if(A[i]==2){
                swap(A[i],A[two--]);
            }else{
                i++;
            }
        }
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {
        int zero=0,one=0,two=0;
        for(int i=0; i<n; i++){
            if(A[i]==2){
                A[two++]=2;
            }else if(A[i]==1){
                A[two++]=2;
                A[one++]=1;
            }else{
                A[two++]=2;
                A[one++]=1;
                A[zero++]=0;
            }
        }
    }
};
