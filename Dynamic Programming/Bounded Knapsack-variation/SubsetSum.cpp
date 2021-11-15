#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
bool solve(int arr[], int n, int sum){
  if(sum==0)
    return true;
  if(n==0)
    return false;
  if(dp[n-1][sum]!=-1)
   return dp[n-1][sum];
  if(arr[n-1]<=sum){
    return dp[n-1][sum]=solve(arr, n-1, sum-arr[n-1])||solve(arr, n-1, sum);
  }else{
    return dp[n-1][sum]=solve(arr, n-1, sum);
  }

}
int top_down(int arr[], int n, int sum){
  bool dp[n+1][sum+1];
  // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
      if(i==0 || j==0){
        dp[i][j]=0;
      }
      else{
        if(arr[i-1]<=j){
          dp[i][j] = dp[i-1][j-arr[i-1]] ||  dp[i-1][j];
        }else
         dp[i][j] = dp[i-1][j];
      }
      
    }
  }
  return dp[n][sum];
}
int main(){
  int set[] = {3, 34, 4, 12, 5, 2}, sum = 9, n=6;
  dp.assign(n, vector<int>(sum+1,-1));
  cout<<top_down(set, n, sum);
}