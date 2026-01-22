#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> inStk;
    stack<int> outStk;
    MyQueue() {

    }

    void push(int x) {
        inStk.push(x);
    }

    int pop() {
        if(outStk.empty()) {
            while(!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
        int ret = outStk.top();
        outStk.pop();
        return ret;
    }

    int peek() {
        if(outStk.empty()) {
            while(!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
        return outStk.top();
    }
    
    bool empty() {
        return inStk.empty() && outStk.empty();
    }
};

