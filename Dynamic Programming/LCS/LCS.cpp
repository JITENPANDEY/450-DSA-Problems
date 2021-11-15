//memoization
int dp[1002][1002]; 
int lcshelper(int x, int y, string s1, string s2){
      // your code here
    if(x==0 || y==0)
    return 0;
    
    if(dp[x][y]!=-1)
        return dp[x][y];
    if(s1[x-1]==s2[y-1])
        return  dp[x][y] = 1 + lcshelper(x-1, y-1, s1, s2);
    else
        return  dp[x][y] = max(lcshelper(x-1, y, s1, s2), lcshelper(x, y-1, s1, s2));
}
int lcs(int x, int y, string s1, string s2)
{
    memset(dp, -1, sizeof(dp)); 
    return lcshelper(x,y,s1,s2);
}

//tabular
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

//space optimized
//tabular
int lcs(int x, int y, string s1, string s2)
{
    int dp[2][y+1];
    for(int i=0;i<=x;i++){
      for(int j=0;j<=y;j++){
        if(i==0 || j ==0)
            dp[i%2][j]=0;
        else{
            if(s1[(i+1)%2]==s2[j-1])
                dp[i%2][j] = 1+dp[i-1][j-1];
            else
                dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
        }
      }
    }
    return dp[x%2][y];
}