#include<bits/stdc++.h>
using namespace std;
vector<long long> nextGreaterElement(vector<long long> &arr, int n){
  vector<long long> ans(n);
  stack<pair<int, int>> s;
  s.push({arr[n-1], n-1});
  ans[n-1]=-1;
  for(int i=n-2;i>=0;i--){
      // pop untill greater element found on top of stack
      while(!s.empty() && arr[i]>s.top().first)
          s.pop();
      
      if(s.empty()) 
          ans[i]=-1;
      else
          ans[i]=s.top().second;
      
      s.push({arr[i],i});
  }
  return ans;
}
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
vector<long long> nextSmallerOfNextGreaterElement(vector<long long> &arr, int n){
  vector<long long> NGEIndex = nextGreaterElement(arr, n);
  vector<long long> NSE = nextSmallerElement(arr, n);

  vector<long long> ans(n);
  for(auto i : NGEIndex){
    ans.push_back(NSE[i]);
  }
  return ans;
}
int main(){
  vector<long long> v = {5, 1, 9, 2, 5, 1, 7};
  vector<long long> ans = nextSmallerOfNextGreaterElement(v, v.size());
  for(auto i : ans) cout<<i<<" ";
  return 0;
}