vector<vector<int>>dp;
int mod = 1e9+7;
int solve(int arr[], int n, int sum){
    if(sum==0)
              return 1;
      if(n==0)
          return 0;
      if(dp[n-1][sum]!=-1)
          return dp[n-1][sum];
      
      if(arr[n-1]<=sum)
          return dp[n-1][sum] = (solve(arr, n-1, sum-arr[n-1])%mod + solve(arr, n-1, sum)%mod)%mod;
      else
          return  dp[n-1][sum] = solve(arr, n-1, sum)%mod;
    
}