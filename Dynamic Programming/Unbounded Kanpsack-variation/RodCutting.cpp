int dp[1001][1001];
int solve(int price[], int length[], int n, int w){
    if(n == 0 or w == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];

    if(length[n-1] > w)
        return dp[n][w] = solve(price, length, n-1, w);

    return dp[n][w] = max(solve(price, length, n, w-length[n-1]) + price[n-1], solve(price, length, n-1, w));
}
int cutRod(int price[], int n) {
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(price, length, n, n);
    return ans;
    
}