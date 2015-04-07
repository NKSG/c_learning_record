#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <unistd.h>
#include <sys/timeb.h>

//假设为ASCII字符
bool isUnique(std::string s){
    if(s.size()>256) return false;

    bool a[256];
    memset(a,0,sizeof(a));

    for(std::string::size_type i=0; i<s.size(); i++){
        int v = static_cast<int>(s[i]);
        if(a[v]) return false;
        a[v] = true;
    }
    return true;
}

bool isUnique_better(std::string s){
    if(s.size()>256) return false;
    std::array<bool,256> a={0};
    for(auto c : s){
        if(a[c]) return false;
        a[c] = true;
    } 
    return true;
}


//假设为小写英文字符
bool isUnique2(std::string s){
    if(s.size()>26) return false;
    int checker = 0;

    for(std::string::size_type i=0; i<s.size(); i++){
        int v = static_cast<int>(s[i]-'a');
        if(checker&(1<<v)) return false;
        checker |= (1<<v);
    }
    return true;
}

int main(){
    std::string g = "abcdefghijklmnopqvwxyz";
    struct timeb start,end;
    ftime(&start);
    isUnique(g);
    ftime(&end);
    long long cost = (end.time-start.time)*1000+(end.millitm-start.millitm);

    std::cout<<isUnique(g)<<cost<<"ms"<<std::endl;
    
    std::cout<<isUnique2(g)<<std::endl;
    return 0;
}
