#include<bits/stdc++.h>
using namespace std;
void print(stack<int> s){
  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }
}
void insert(stack<int> &s, int x){
  if(s.empty() || x<=s.top()) {
    s.push(x);
    return;
  }
  int y = s.top();
  s.pop();
  insert(s, x);
  s.push(y);
}
void sort(stack<int> &s){
  if(s.size()==1) {
    return;
  }
  int x = s.top();
  s.pop();
  sort(s);
  insert(s, x);
}
int main(){
  stack<int> s;
  s.push(11);
  s.push(2);
  s.push(32);
  s.push(4);
  s.push(51);

  cout<<"original stack: "<<endl;
  print(s);

  sort(s);

  cout<<"sorted stack: "<<endl;
  print(s);
  
}