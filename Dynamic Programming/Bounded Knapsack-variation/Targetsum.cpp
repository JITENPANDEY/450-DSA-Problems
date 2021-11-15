 map<pair<int,int>, int>dp;
    int solve(vector<int>& nums,int n, int target){
        //base cases
        if(n==0){
            if(target==0)
                return 1;
            else
                return 0;
        }
        if(dp.find({n-1,target})!=dp.end())
            return dp[{n-1,target}];
        return dp[{n-1,target}] = solve(nums, n-1, target-nums[n-1]) + solve(nums, n-1, target-(-1*nums[n-1]));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, n, target);
    }