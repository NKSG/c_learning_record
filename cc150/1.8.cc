#include <iostream>
#include <string>

bool isSubstring(std::string s1, std::string s2){
    if(s1.find(s2)!=std::string::npos) return true;
    return false;
}

bool isRotation(std::string s1, std::string s2){
    if(s1.size()!=s2.size()) return false;
    return isSubstring(s1+s1,s2);
}

int main(){
    std::string a("apple");
    std::string b("pleap");
    std::cout<<isRotation(a,b)<<std::endl;

}
