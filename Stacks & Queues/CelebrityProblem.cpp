#include<bits/stdc++.h>
using namespace std;
int findCelebrity(int n , int M[N][N]){

  stack<int> s;
  for(int i=n-1;i>=0;i--)
  s.push(i);
  
  while(s.size()>1){
      int A = s.top();
      s.pop();
      int B = s.top();
      s.pop();
      if(M[A][B] == 1){ // A knows B then B can be a celebrity
          s.push(B);
      }
      else
      s.push(A); // A doesn't know B then A can be a celebrity
  }
  
  int C = s.top();
  s.pop();
  for(int i=0;i<n;i++){
      if(i!= C && (M[C][i]==1 || M[i][C]==0))
      return -1;
  }
  return C;

  /*---------------------------------------------------------------------------------------------------------
  O(N^2)
  int heknows[n+1]={0};
  int heisknown[n+1]={0};
  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          if(M[i][j]==1){
              heknows[i]+=1;
          heisknown[j]+=1;
          }
          
      }
  }
  for(int i=0;i<n;i++){
      
      if(heknows[i]==0 && heisknown[i]==n-1)
      return i;
  }
  return -1;
  */
}
int main(){
  
}