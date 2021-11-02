#include<bits/stdc++.h>
using namespace std;
int findMaxLen(string s) {
  // code here
  stack<int> stk;
  stk.push(-1);
  int ans =0;
  for( int i=0;i<s.length();i++){
      if(s[i]=='(')
      stk.push(i);
      else{
          stk.pop();
          if(stk.empty()==false)
              ans = max(ans, i-stk.top());
          else
              stk.push(i);
      }
  }
  return ans;
}
int main(){
  
}