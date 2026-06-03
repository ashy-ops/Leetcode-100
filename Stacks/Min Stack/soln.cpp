#include <bits/stdc++.h>
using namespace std;

class MinStack {

private:
    pair<int,int> st[3*10000+5];
    int ptr;
public:
    MinStack() {
        ptr = -1;
    }
    
    void push(int val) {
        if(ptr==-1) st[++ptr] = {val,val};
        else {
            ptr++;
            st[ptr]= {val,min(val, st[ptr-1] .second)};
        }
    }
    
    void pop() {
        ptr--;
    }
    
    int top() {
        return st[ptr].first;
    }
    
    int getMin() {
        return st[ptr].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */