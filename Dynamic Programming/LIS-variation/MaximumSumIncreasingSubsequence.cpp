{1, 101, 2, 3, 100, 4, 5};
{1, 102, 3, 6, 106, 10, 15};
int maxSumIS(int arr[], int n)
{
    int i, j, ans = arr[0];
    int dp[n];
 
    /* Initialize msis values
    for all indexes */
    for ( i = 0; i < n; i++ )
        dp[i] = arr[i];
 
    for(int i=1;i<n;i++){
      for(int j=0;j<i;j++){
        if(arr[i]>arr[j]){
          dp[i] = max(dp[i], arr[i]+dp[j]);
          ans = max(ans, dp[i]);
        }
      }
    }
}