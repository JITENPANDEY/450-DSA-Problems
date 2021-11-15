//DP = O(N^2)
int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int>dp(pairs.size(), 1);
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return dp[pairs.size() - 1];
        
    }

//Greedy = O(NLogN)
sort(pairs.begin(), pairs.end(), [](vector<int>&a, vector<int>&b){
          return a[1]<b[1];
      });
int ans = 1;
  int lastChainedPair = pairs[0][1];
  for (int i = 1; i < pairs.size(); i++) {
      if(pairs[i][0]>lastChainedPair){
          ans++;
          lastChainedPair = pairs[i][1];
      }
  }
return ans;