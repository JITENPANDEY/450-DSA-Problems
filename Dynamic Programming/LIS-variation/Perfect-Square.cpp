int perfectSqaure(int n ){
  int dp[n+1];
  dp[0] = 0, dp[1]=1;
  for(int i=2;i<=n;i++){
    int mini = INT_MAX;
    for(int j=1;i*i<=j;j++){
      mini = max(mini, dp[i - j*j]);
    }
    dp[i]=mini+1;
  }

}