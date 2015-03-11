#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
/*practice 1
int main(){
  string line;
  while(getline(cin,line)){
    int sum = 0,x;
    stringstream ss(line);
    while(ss>>x) sum += x;
    cout<<sum<<"\n";
  }
  return 0;
}
*/

int main(){
  string line;
  while(getline(cin,line)){
    stringstream ss(line);
    int sum = 0, x;
    while(ss>>x) sum += x;
    cout<<sum<<"\n";
  }
  return 0;

}
