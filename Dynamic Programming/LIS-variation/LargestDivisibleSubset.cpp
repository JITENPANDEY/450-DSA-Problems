vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int>dp(nums.size(), 1);
        vector<int>prev_index(nums.size(), -1);
        int maxLenIdx = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
               if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                       dp[i]=dp[j]+1;
                       prev_index[i] = j;
            }
            if(dp[i] > dp[maxLenIdx])
               maxLenIdx = i;
            }
        }
        
        // nums[] =1,2,3,4,5
        // dp[] =  1 2 2 3 2
        // prev[]=-1 0 0 1 0
        //cout<<maxLenIdx;
        vector<int>ans;
        while(maxLenIdx!=-1){
            ans.push_back(nums[maxLenIdx]);
            maxLenIdx = prev_index[maxLenIdx];    
        }
        return ans;
    }