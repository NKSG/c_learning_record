#include <string>
#include <iostream>

void replaceSpaces2(char* str, int length){
    int spaceCount = 0, i;
    for(i=0; i<length; ++i){
        if(str[i]==' ') spaceCount++;
    }
    int newLength = spaceCount*2+length;
    str[newLength] = '\0';
    for(i = length-1; i>=0; i--){
        if(str[i]==' '){
            str[newLength-1] = '0';
            str[newLength-2] = '2';
            str[newLength-3] = '%';
            newLength = newLength-3;
        }else{
            str[newLength-1] = str[i];
            newLength = newLength-1;
        }
    }
}

void replaceSpaces(std::string &str){
    int pos = 0;
    while((pos = str.find_first_of(' ',pos)) != std::string::npos){
        //find可以找" ",' ',c风格字符串
        str.replace(pos,1,"%20");
        //返回指向str的引用
    }
}

int main(){
    std::string str("ab cd e fg h i ");
    char str2[100] = {"ab cd e fg h i "};
    replaceSpaces2(str2,15);
    replaceSpaces(str);
    std::cout<<str2<<std::endl;
    std::cout<<str<<std::endl;
}
