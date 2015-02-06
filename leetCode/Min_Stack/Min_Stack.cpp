//
//  main.cpp
//  Min_Stack
//
//  Created by liaogang on 14/11/11.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
/**
 
     Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
     
     push(x) -- Push element x onto stack.
     pop() -- Removes the element on top of the stack.
     top() -- Get the top element.
     getMin() -- Retrieve the minimum element in the stack.

 */

class MinStack {
private:
    deque<int> st;
    deque<int> mi;
public:
    void push(int x) {
        st.push_back(x);
        if (mi.empty() || x <= mi.back()) mi.push_back(x);
    }
    
    void pop() {
        if (st.empty()) return;
        if (st.back() == mi.back()) mi.pop_back();
        st.pop_back();
    }
    
    int top() {
        if (st.empty()) return -1;
        return st.back();
    }
    
    int getMin() {
        if (mi.empty()) return -1;
        return mi.back();
    }
};


int main(int argc, const char * argv[])
{

//    push(395),getMin,top,getMin,push(276),push(29),getMin,push(-482),getMin,pop,push(-108),push(-251),getMin
    
    
    MinStack s;
    
    s.push(395);
    cout<<s.getMin()<<endl;
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    s.push(276);
    s.push(29);
    cout<<s.getMin()<<endl;
    s.push(-482);
    cout<<s.getMin()<<endl;
    s.pop();
    s.push(-108);
    s.push(-251);
    cout<<s.getMin()<<endl;
    
    //push(-439),top,push(370),pop,pop,getMin,pop,getMin,getMin,pop,getMin,
    s.push(-439);
    cout<<s.top()<<endl;
    s.push(370);
    s.pop();
    s.pop();
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    
    
    
    
//    cout<<s.getMin()<<endl;
//    cout<<s.getMin()<<endl;
//    s.pop();
//    cout<<s.getMin()<<endl;
//    cout<<s.getMin()<<endl;
//    
    return 0;
}
