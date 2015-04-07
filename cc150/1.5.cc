#include <string>
#include <iostream>

std::string compress(const std::string &str){
    std::string result;    
    if(str.empty()) return result;
    char last = *str.begin();
    int count = 0;
    for(auto c : str){
        if(c==last){
            count++;
        }else{
            result += last+std::to_string(count);
            count = 1;
            last = c;
        }
    }
    result += last+std::to_string(count);
    return (result.size()<str.size()?result:str);
}


int main(){
    std::string a("aabbbccccdddddeefgg");
    std::string b("abcd");
    std::cout<<compress(b)<<std::endl;
}
