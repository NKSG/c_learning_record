#include <iostream>
#include <p105_point.cpp>
using namespace std;

int sum(int* begin, int* end){
  int* p =begin;
  int s = 0;
  for(int* p = begin; p!=end; p++)
    s += *p;
  return s;
}

template<typename T>
T sum(T* begin, T* end){
  T* p = begin;
  T s=0;
  for(T* p = begin; p!=end; p++)
    s = s + *T;
  return s;
}

int main(){
  double a[]={1.1,2.2,3.3,4.4};
  cout<<sum(a,a+4)<<"\n";
  Point b[]={Point(1,2),Point(3,4),Point(5,6),Point(7,8)};
  cout<<sum(b,b+4)<<"\n";
  return 0;
}
