int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // dp[k][v] = dist to reach v using k stops
        vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX));
        
        // for src dp[k][src] = 0 always
        for(int i=0;i<=k+1;i++){
            dp[i][src] = 0;
        }
        
        for(int i=1;i<=k+1;i++){
            for(auto &f : flights){
                int u = f[0], v = f[1], cost = f[2];
                if(dp[i-1][u]!=INT_MAX){
                    dp[i][v] = min(dp[i-1][u] + cost, dp[i][v]);
                }
            }
        }
        return (dp[k+1][dst]==INT_MAX) ? -1 : dp[k+1][dst];
    }