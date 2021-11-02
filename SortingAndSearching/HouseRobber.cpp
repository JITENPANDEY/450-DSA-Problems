    //include - take the current and go to the next of next
    //exclude - go to the next 
int dp[10001];
int recur(int arr[], int i){
    if(i<0) return 0;
    if(dp[i]!=-1)
        return dp[i];
    dp[i] = max(recur(arr,i-1), recur(arr,i-2)+arr[i]); 
    return dp[i];
}
int FindMaxSum(int arr[], int n)
{
    memset(dp,-1,sizeof(dp));
    return recur(arr,n-1);
}
