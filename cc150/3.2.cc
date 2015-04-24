#include <stack>
#include <iostream>

class MinStack{
    std::stack<int> stack,smin;
public:
    void push(int data){
        stack.push(data);
        if(smin.empty()||data<=smin.top()){
            smin.push(data);
        }
    }

    void pop(){
        if(stack.empty()){
            //栈空
        }else{
            if(smin.top()==stack.top()){
                smin.pop();
            }
            stack.pop();
        }
    }

    int top(){
        if(stack.empty()){
            //栈空
        }else{
            return stack.top();
        }
    }

    int min(){
        if(stack.empty()){
            //栈空
        }else{
            return smin.top();
        }
    }

};

int main(){
    MinStack s;
    s.push(3);
    s.push(4);
    s.push(10);
    s.push(1);
    std::cout<<s.min()<<std::endl;
    s.pop();s.pop();
    std::cout<<s.min()<<" "<<s.top()<<std::endl;

}
