#include <iostream>

void reverse(char* str){
    char *start = str;
    char *end = str;
    if(str){
        while(*end) end++;
        end--;
//因为操作的是指针，所以真正得以改变
        while(start<end){
            std::swap(*start++,*end--);
        }
    }
}
//c风格字符串 char* []
//在<cstring>中定义了如下操作：
//strlen(p); strcmp(p1,p2); strcat(p1,p2);strcpy(p1,p2);
//但是p必须为指向以空字符作为结束的数组。


void reverse2(char* str){
    if(strlen(str)<=1) return;
    for(int i=0; i<(strlen(str)>>1); i++){
        std::swap(str[i],str[strlen(str)-i-1]);
    }
}

int main(){
    char b[] = "abcdefghijklmnopqr";
    std::cout<<b<<std::endl;
    reverse2(b);
    std::cout<<b<<std::endl;
    reverse2(b);
    std::cout<<b<<std::endl;
    return 0;
}

