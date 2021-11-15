int lcs(int x, int y, string s1, string s2)
{
  int dp[x+1][y+1];
  for(int i=0;i<=x;i++){
    for(int j=0;j<=y;j++){
      if(i==0 || j ==0)
          dp[i][j]=0;
      else{
          if(s1[i-1]==s2[j-1])
              dp[i][j] = 1+dp[i-1][j-1];
          else
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[x][y];
}
int shortestSuperSequence(char* X, char* Y)
{
  int m = strlen(X), n = strlen(Y);

  // find lcs
  int l = lcs(X, Y, m, n);

  // Result is sum of input string
  // lengths - length of lcs
  return (m + n - l);
}

//recursive
int superSeq(char* X, char* Y, int m, int n)
{
    if (!m)
        return n;
    if (!n)
        return m;
 
    if (X[m - 1] == Y[n - 1])
        return 1 + superSeq(X, Y, m - 1, n - 1);
 
    return 1
           + min(superSeq(X, Y, m - 1, n),
                 superSeq(X, Y, m, n - 1));
}