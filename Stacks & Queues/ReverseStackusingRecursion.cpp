#include<bits/stdc++.h>
using namespace std;
void print(stack<int> s){
  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }
}
void insertAtBottom(stack<int> &s, int x){
  if(s.empty()) {
    s.push(x);
    return;
  }
  int y = s.top();
  s.pop();
  insertAtBottom(s, x);
  s.push(y);
}
void reverse(stack<int> &s){
  if(s.size()==1) {
    return;
  }
  int x = s.top();
  s.pop();
  reverse(s);
  insertAtBottom(s, x);
}
int main(){
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  cout<<"original stack: "<<endl;
  print(s);

  reverse(s);

  cout<<"reverse stack: "<<endl;
  print(s);
  
}