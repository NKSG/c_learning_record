#include <iostream>
using namespace std;
class stack3{
    const static int stackSize = 100;
    int stack[3*stackSize] = {0};
    int pointer[3] = {-1};

public:
    
    
    void push(int stackNum, int value){
        if(pointer[stackNum] == stackSize){
            //栈满
        }else{
            pointer[stackNum]++;
            stack[stackNum*stackSize+pointer[stackNum]] = value;
        }
    }

    void pop(int stackNum){
        if(pointer[stackNum] == -1){
            //栈空
        }else{
            --pointer[stackNum];
        }
    }

    int top(int stackNum){
        if(pointer[stackNum] == -1){
            return -1;//栈空
        }else{
            return stack[stackNum*stackSize+pointer[stackNum]];
        }
    }

    bool empty(int stackNum){
        return pointer[stackNum] == -1;
    }

};

int main(){
    stack3 s;
    for(int i=0; i<10; ++i){
        s.push(0,i);
        s.push(1,2*i);
        s.push(2,3*i);
    }

    cout<<s.top(0)<<" "<<s.top(1)<<" "<<s.top(2)<<endl;
    s.pop(0);
    s.pop(1);
    s.push(2,100);
    cout<<s.top(0)<<" "<<s.top(1)<<" "<<s.top(2)<<endl;



}
