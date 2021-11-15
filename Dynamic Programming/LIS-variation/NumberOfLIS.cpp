//     The idea is to use two arrays len[n] and cnt[n] to record the maximum length of Increasing Subsequence and the coresponding number of these sequence which ends with nums[i], respectively. That is:

// len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
// cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].

// Then, the result is the sum of each cnt[i] while its corresponding len[i] is the maximum length.
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        vector<int>count(nums.size(), 1);
        for(int i=0;i<nums.size();i++){
          for(int j=0;j<i;j++){
              if(nums[i]>nums[j]){
                 if(dp[i]<=dp[j]){
                     dp[i] = dp[j]+1;
                     count[i]=count[j];
                 }else if(dp[i]==dp[j]+1){
                     count[i]+=count[j];
                 }
              }
          }
      }
        int ans =0;
      int maxLength = *max_element(dp.begin(), dp.end());
        for(int i=0;i<dp.size();i++){
            if(dp[i]==maxLength)
                ans += count[i];
        }
      return ans;
    }