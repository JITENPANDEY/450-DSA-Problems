int knapsack(int wt[], int val[], int n, int w) {
    if(n == 0 or w == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];

    if(wt[n-1] > w)
        return dp[n][w] = knapsack(wt, val, n-1, w);

    return dp[n][w] = max(knapsack(wt, val, n, w-wt[n-1]) + val[n-1], knapsack(wt, val, n-1, w));
}
int knapsack(int wt[], int val[], int n, int w) {
    int dp[n+1][w+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++){
            if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i][j-wt[i-1]] + val[i-1], dp[i-1][j]);
        }
    }
    return dp[n][w];
}
int knapsack(int wt[], int val[], int n, int w) {
    int dp[w+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = wt[i]; j <= w; j++){
            dp[j] = max(dp[j], dp[j-wt[i]] + val[i]);
        }
    }
    return dp[w];
}