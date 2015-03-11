#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
  string s, result_s;
  bool has_punct = false;
  char ch;

  cout<<"enter a string: "<<endl;
  getline(cin,s);
  for(string::size_type index = 0; index!=s.size();++index){
    ch = s[index];
    if(ispunct(ch))
      has_punct = true;
    else
      result_s += ch;
  }
  if(has_punct)
    cout<<"Result:"<<endl<<result_s<<endl;
  else{
    cout<<"No punctuation character in the string."<<endl;
    return -1;
  }
  return 0;


}
