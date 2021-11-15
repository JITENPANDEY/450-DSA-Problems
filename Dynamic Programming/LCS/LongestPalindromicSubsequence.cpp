int dp[1001][1001];
int LPS(string &s, int i, int j){
    if(i==j)
        return 1;
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i] == s[j]){
        return dp[i][j] = 2+LPS(s, i+1, j-1);
    }else{
        return dp[i][j] = max(LPS(s, i+1, j), LPS(s, i, j-1));
    }
}
int longestPalindromeSubseq(string s) {
    memset(dp, -1, sizeof dp);
    return LPS(s, 0, s.length()-1);
}