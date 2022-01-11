int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp; // num, index
        mp[0]=-1;
        int ans =0, sum =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                sum+=-1;
            else
                sum+=nums[i];
            
            if(mp.find(sum)!=mp.end())
                ans = max(ans, i-mp[sum]);
            else
                mp[sum]=i;  
        }
        return ans;
    }