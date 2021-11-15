int lengthOfLIS(vector<int>& nums) {
  vector<int>dp(nums.size(), 1);
  int ans = 0;
  for(int i=0;i<nums.size();i++){
      int currMax = 1;
      for(int j=0;j<i;j++){
          if(nums[i]>nums[j]){
              dp[i] = max(dp[i], dp[j]+1);
              currMax = max(dp[i], currMax);
          }
      }
      ans = max(ans, currMax);
  }
  return ans;
}
//nums= [0,1,0,3,2,3]
// dp = [1,2,1,3,3,4]
// dp[i] represent the LIS ends with nums[i]

//O(NLogN)
vector<int>dp;
dp.push_back(nums[0]);
for(int i=1;i<nums.size();i++){
    if(nums[i]>dp.back())
        dp.push_back(nums[i]);
    else{
        int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
        dp[index] = nums[i];
    }
}
return dp.size();