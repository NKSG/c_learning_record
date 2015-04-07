#include <iostream>
#include <algorithm>
#include <string>
#include <array>
/*
std::string sort(const std::string &s){
    std::string temp(s);
    std::sort(temp.begin(),temp.end());
    return temp;
}
*/

bool permutation(std::string s1, std::string s2){
    if(s1.size()!=s2.size()) return false;
    /*
    std::string s1_new = sort(s1);
    std::string s2_new = sort(s2);
    */
    std::sort(s1.begin(),s1.end());
    std::sort(s2.begin(),s2.end());
    return std::equal(s1.begin(),s1.end(),s2.begin());
}

bool permutation2(std::string s1, std::string s2){
    if(s1.size()!=s2.size()) return false;
    std::array<int,256> a={0};
    for(auto c : s1){
        a[c]++;
    }
    for(auto c : s2){
        if(--a[c]<0) return false;
    }
    return true;
}


int main(){
    std::string s1("i am a dogd");
    std::string s2("goa d mai c");
    std::cout<<permutation2(s1,s2)<<std::endl;

}

