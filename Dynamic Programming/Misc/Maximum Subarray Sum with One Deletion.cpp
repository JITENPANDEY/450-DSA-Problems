/*
    I believe dp[i][0] represents maximum subarray sum upto index i with no deletions, dp[i][1] represents maximum subarray sum upto index i with one deletion done.

dp[i][0] = maxSumWithNoDeletionUptoThisIndex = max(currentNum, maxSumWithNoDeletionUptoLastIndex + currentNum)

dp[i][1] = maxSumWithOneDeletionUptoThisIndex = max(currentNum, max(maxSumWithNoDeletionUptoLastIndex, maxSumWithOneDeletionUptoLastIndex + currentNum))
    */
    int maximumSum(vector<int>& arr) {
        int n= arr.size();
        vector<vector<int>>dp(n, vector<int>(2, 0));
        
        dp[0][0] = arr[0];
        int ans = arr[0];
        
        for(int i=1;i<n;i++){
            int currNum = arr[i];
            int maxSumWithNoDeletionUptoLastIndex = dp[i-1][0];
            int maxSumWithOneDeletionUptoLastIndex = dp[i-1][1];
            
            
            dp[i][0] = max(currNum, maxSumWithNoDeletionUptoLastIndex + arr[i]); // no deletion upto this index
            dp[i][1] = max({currNum, maxSumWithNoDeletionUptoLastIndex, maxSumWithOneDeletionUptoLastIndex + currNum});
            ans = max({ans, dp[i][0], dp[i][1]});
           
        }
         return ans;
    }