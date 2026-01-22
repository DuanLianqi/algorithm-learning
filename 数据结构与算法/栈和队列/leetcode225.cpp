#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> first;
    queue<int> second;
    MyStack() {
        
    }

    void push(int x) {
        first.push(x);
    }

    int pop() {
        int sz = first.size();
        while(--sz) {
            second.push(first.front());
            first.pop();
        }
        int ret = first.front();
        first.pop();

        while(!second.empty()) {
            first.push(second.front());
            second.pop();
        }
        return ret;
    }

    int top() {
        int sz = first.size();
        while(--sz) {
            second.push(first.front());
            first.pop();
        }
        int ret = first.front();
        second.push(first.front());
        first.pop();

        while(!second.empty()) {
            first.push(second.front());
            second.pop();
        }
        return ret;
    }

    bool empty() {
        return first.empty();
    }
};