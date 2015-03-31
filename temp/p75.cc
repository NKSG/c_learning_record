#include <string>
#include <iostream>
using namespace std;

int main(){
    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    for(auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout<<punct_cnt<<" punctuation characters in "<<s<<endl;
    
    /*for(auto &c : s)
        c = toupper(c);
    cout<<s<<endl;
    */
    for(decltype(s.size()) index = 0; index!=s.size() && !isspace(s[index]); ++index){
        s[index] = toupper(s[index]);
    }
    cout<<s<<endl;

    const string hexdigits = "0123456789ABCDEF";
    cout<<"Enter"<<endl;
    string result;
    string::size_type n;
    while(cin>>n){
        if(n<hexdigits.size())
            result += hexdigits[n];
    }
    cout<<"result: "<<result<<endl;

    return 0;
}
