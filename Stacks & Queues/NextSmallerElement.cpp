#include<bits/stdc++.h>
using namespace std;
vector<long long> nextSmallerElement(vector<long long> &arr, int n){
  // Your code here
  vector<long long> ans(n);
  stack<long long> s;
  s.push(arr[n-1]);
  ans[n-1]=-1;
  for(int i=n-2;i>=0;i--){
      // pop untill greater element found on top of stack
      while(!s.empty() && arr[i]<s.top())
          s.pop();
      
      if(s.empty()) 
          ans[i]=-1;
      else
          ans[i]=s.top();
      
      s.push(arr[i]);
  }
  return ans;
}
int main(){
  vector<long long> v = {6, 8, 0, 1, 3};
  vector<long long> ans = nextSmallerElement(v, v.size());
  for(auto i : ans) cout<<i<<" ";
  return 0;
}