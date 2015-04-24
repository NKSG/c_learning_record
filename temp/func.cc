#include "xxx.h"
using namespace std;
int fact(int n){
    if(n<0) return -1;
    int ret=1;
    for(int i=1; i != n+1; ++i)
        ret *= i;
    return ret;
}
