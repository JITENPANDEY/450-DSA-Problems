#include<bits/stdc++.h>
using namespace std;
//Function to find largest rectangular area possible in a given histogram.
vector<long long> NSERightIndex(long long arr[], int n){
// Your code here
vector<long long> ans(n);
stack<long long> s;
s.push(n-1);
ans[n-1]=n;
for(int i=n-2;i>=0;i--){
    // pop untill greater element found on top of stack
    while(!s.empty() && arr[i]<=arr[s.top()])
        s.pop();
    
    if(s.empty()) 
        ans[i]=n;
    else
        ans[i]=s.top();
    
    s.push(i);
}
return ans;
}
vector<long long> NSELeftIndex(long long arr[], int n){
// Your code here
vector<long long> ans(n);
stack<long long> s;
s.push(0);
ans[0]=-1;
for(int i=1;i<n;i++){
    // pop untill greater element found on top of stack
    while(!s.empty() && arr[i]<=arr[s.top()])
        s.pop();
    
    if(s.empty()) 
        ans[i]=-1;
    else
        ans[i]=s.top();
    
    s.push(i);
}
return ans;
  }
long long getMaxArea(long long arr[], int n)
{
  // Your code here
  vector<long long> NSE_Left= NSELeftIndex(arr, n);
  vector<long long> NSE_Right = NSERightIndex(arr, n);
  
  long long ans = -1;
  for(int i=0;i<n;i++){
      ans = max(ans, (NSE_Right[i]- NSE_Left[i]-1)*arr[i]);
  }
  return ans;
}
int main(){
  
}
  