int dp[100]={0};
int integerBreak(int n) {
    if(n==1)
        return 1;
    if(dp[n])
        return dp[n];
    
    int maxProduct =0;
    for(int x =1;x<n;x++){ //for(int x =1;x<=n/2;x++){
        int y = n-x;
        int p1 = integerBreak(x);
        int p2 = integerBreak(y);
        maxProduct = max(maxProduct, max(x, p1)*max(y, p2));
    }
    return dp[n] =maxProduct;
}