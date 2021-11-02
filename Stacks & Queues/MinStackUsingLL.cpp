#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int val;
    int min;
    Node* next;
    Node(int val, int min, Node* next) {
        this->val = val;
        this->min = min;
        this->next = next;
    }  
};
class MinStack {
  public:
    Node* head = NULL;
    void push(int val){
        if(head==NULL){
            head = new Node(val, val, NULL);
        }else{
            head = new Node(val, min(val, head->min), head);
        }
    }
    void pop(){
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    int top(){
        return head->val;
    }
    int getMin(){
        return head->min;
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