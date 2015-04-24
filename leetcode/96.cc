//No.96
//https://leetcode.com/problems/unique-binary-search-trees/
//Unique Binary Search Trees
class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        int r=0;
        for(int i=1; i<=n; i++)
            r+= numTrees(i-1)*numTrees(n-i);
        return r;
    }
};

int f(int n){
    const int size = n+1;
    vector<int> cache(size,1);
    for(int i=2; i<n; i++){
        int result = 0;
        for(int j=1; j<=i; j++)
            result += cache[j-1]*cache[i-j];
        cache[i] = result;
    }
    return cache[n];
}
int numTrees(int n){
    if(n==0) return 0;
    return f(n);
}


/*  */

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1,0);
        f[0]=1;
        f[1]=1;
        for(int i=2; i<=n; ++i){
            for(int k=1; k<=i; ++k)
                f[i]+=f[k-1]*f[i-k];
        }
        return f[n];
    }
};
