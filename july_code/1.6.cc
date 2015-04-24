//字符串的全排列
//1.递归实现//暂时不太理解啊
void CalcAllPermutation(char* perm, int from , int to){
    if(to<=1) return;
    if(from == to){
        for(int i=0; i<=to; i++)
            cout<<perm[i];
        cout<<endl;
    }else{
        for(int j=from; j<=to; j++){
            swap(perm[j],perm[from]);
            CalcAllPermutation(perm,from+1,to);
            swap(perm[j],perm[from]);
        }
    }
}

//2.next_permutation
//
