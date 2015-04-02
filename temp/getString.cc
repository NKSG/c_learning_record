#include <string>
#include <vector>
using namespace std;
int getLongestStr(char *str1, int m, char *str2, int n){
    int max = 0;
    vector<vector<int> > array(m,vector<int>(n,0));
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            if(str1[i]==str2[j]){
                if(i>0 && j>0){
                    array[i][j] = array[i-1][j-1]+1;
                }else{
                    array[i][j] = 1;
                }
                if(array[i][j]> max){
                    max = array[i][j];
                }
            }
        }
    return max;
}
