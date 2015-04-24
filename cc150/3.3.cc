#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class SetOfStacks{
    vector<stack<int> > stacks;
    int maxSize = 10;

    stack<int> getLastStack(){
        //if(stacks.size()==0) xx?;
        return stacks.back();
    }
    

    void push(int data){
        stack<int> last = getLastStack();
        if(last.size()!=maxSize){
            last.push(data);
        }else{
            stack<int> stack;
            stack.push(data);
            stacks.push_back(stack);
        }
    }

    int pop(){
        stack<int> last = getLastStack();
        int val = last.top();
        last.pop();
        if(last.empty()) stacks.pop_back();
        return val;
    }


};
