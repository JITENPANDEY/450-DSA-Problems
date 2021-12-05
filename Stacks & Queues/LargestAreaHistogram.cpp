#include<bits/stdc++.h>
using namespace std;
//Function to find largest rectangular area possible in a given histogram.
vector<int> NSERightIndex(int arr[], int n){
// Your code here
vector<int> ans(n);
stack<int> s;
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
vector<int> NSELeftIndex(int arr[], int n){
// Your code here
vector<int> ans(n);
stack<int> s;
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
int getMaxArea(int arr[], int n)
{
  // Your code here
  vector<int> NSE_Left= NSELeftIndex(arr, n);
  vector<int> NSE_Right = NSERightIndex(arr, n);
  
  int ans = -1;
  for(int i=0;i<n;i++){
      ans = max(ans, (NSE_Right[i]- NSE_Left[i]-1)*arr[i]);
  }
  return ans;
}
int main(){
  
}



//
int n = heights.length; 
Stack<Integer> st = new Stack<>();
int leftSmall[] = new int[n]; 
int rightSmall[] = new int[n]; 
for(int i = 0;i<n;i++) {
    while(!st.isEmpty() && heights[st.peek()] >= heights[i]) {
        st.pop(); 
    }
    
    if(st.isEmpty()) leftSmall[i] = 0; 
    else leftSmall[i] = st.peek() + 1; 
    st.push(i); 
}

// clear the stack to be re-used
while(!st.isEmpty()) st.pop(); 

for(int i = n-1;i>=0;i--) {
    while(!st.isEmpty() && heights[st.peek()] >= heights[i]) {
        st.pop(); 
    }
    
    if(st.isEmpty()) rightSmall[i] = n-1; 
    else rightSmall[i] = st.peek() - 1;
    
    st.push(i); 
}

int maxA = 0; 
for(int i = 0;i<n;i++) {
    maxA = Math.max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
}
return maxA; 
  