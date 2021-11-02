#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int>s1;
    stack<int>s2;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s2.size()==0 || val<=s2.top()){
            s2.push(val);
        }
        s1.push(val);
    }
    
    void pop() {
        if(s1.top()==s2.top()){
            s1.pop();
            s2.pop();
        }else{
            s1.pop();
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
int main()
{
    MinStack s;
    s.push(3);
    s.push(5);
    cout<<s.getMin()<<endl;
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
 
    return 0;
}
       