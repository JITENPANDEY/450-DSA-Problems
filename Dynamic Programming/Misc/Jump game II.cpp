int jump(vector<int>& nums) {
        int n = nums.size();
        
        //DP solution O(N^2)
//         vector<int> dp(n, INT_MAX);
//         dp[n-1]=0;
        
//         for(int i=n-2;i>=0;i--){
//             int mini = INT_MAX;
//             for(int j=i+1;j<=min(nums[i]+i, n-1);j++){
//                     mini = min(mini, dp[j]);
//             }
//             if(mini!=INT_MAX){
//                 dp[i] = mini+1;
//             }
            
//         }
//         // for(int i=0;i<n;i++){
//         //     cout<<i<<"->"<<dp[i]<<endl;
//         // }
//         return dp[0];
        
        //greedy
        int currReach=0;
        int maxReach =0;
        int jumps=0;
        if(n==1) return 0;
        
        for(int i=0;i<n-1;i++){
            
            if(maxReach<nums[i]+i){
                maxReach = nums[i]+i;
                cout<<"maxReach="<<maxReach<<endl;
            }
            //we will not take any jump if my currReach is less than the max reach
            // we will only take  jump if 
            if(i==currReach){
                currReach = maxReach;
                jumps++;
                cout<<"currReach = "<<currReach<<endl;
            }
                
        }
        return jumps;
    }