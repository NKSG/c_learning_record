//No.155
//https://leetcode.com/problems/min-stack/
//min-stack
class MinStack {
    stack<int> data;
    stack<int> min;
public:
    void push(int x) {
        if(min.empty()){
            data.push(x);
            min.push(x);
            return;
        }
        data.push(x);
        if(x<=min.top())
            min.push(x);
    }

    void pop() {
        if(!min.empty()){
            if(data.top() == min.top())
                min.pop();
            data.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};
