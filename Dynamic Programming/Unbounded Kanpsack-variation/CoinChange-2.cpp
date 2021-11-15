long long int dp[1001][1001];
long long int solve(int coins[], int n, int amount){
  if(amount==0)
      return 1;
  else if(n==0)
      return 0;
  if(dp[n-1][amount]!=-1)
      return dp[n-1][amount];
  else if(coins[n-1]<=amount)
      return dp[n-1][amount] = solve(coins, n, amount-coins[n-1]) + solve(coins, n-1, amount);
  else
      return dp[n-1][amount] = solve(coins, n-1, amount);
}
long long int count(int coins[], int m, int n) {

  memset(dp, -1, sizeof dp);
    long long int ans = solve(coins, m, n);
  return ans;
}