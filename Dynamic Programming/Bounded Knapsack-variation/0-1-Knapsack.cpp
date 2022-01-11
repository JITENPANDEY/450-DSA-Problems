#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int solve(int wt[], int val[], int Cap, int n){
  if(Cap==0 || n==0)
    return 0;
  if(dp[n][Cap]!=-1)
    return dp[n][Cap];
  if(wt[n]<=Cap){
    return dp[n][Cap] = max(val[n] + solve(wt, val, Cap-wt[n], n-1) , solve(wt, val, Cap, n-1));
  }else{
    return dp[n][Cap] = solve(wt, val, Cap, n-1);
  }
}
int top_down(int wt[], int val[], int n, int w){
  int dp[n+1][w+1];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=w;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
      else{
        if(wt[i-1]<=j){
          dp[i][j] = max(dp[i-1][j-arr[i-1]]+val[i-1], dp[i-1][j]);
        }else
         dp[i][j] = dp[i-1][j];
      }
      
    }
  }
  return dp[n][w];
}
int main(){
  int wt[] = {10,20,30};
  int val[]= { 60, 100, 120};
  int n =3;
  int Cap = 50;
  dp.assign(n, vector<int>(Cap+1,-1));
  cout<<top_down(wt, val, n, Cap);
}