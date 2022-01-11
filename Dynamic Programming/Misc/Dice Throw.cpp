long long dp[1000][1000];
long long solve(int M , int N , int X){
        // code here
    if(N==0 && X==0) return 1;
    else if(N==0 || X<=0) return 0;
    
    if(dp[N][X]!=-1) return dp[N][X];
    
    long long count = 0;
    for(int i=1;i<=min(X, M);i++){
        count += solve(M, N-1, X-i);
    }
    return dp[N][X] = count;
}
long long noOfWays(int M , int N , int X) {
    memset(dp, -1, sizeof dp);
    return solve(M, N, X);
}