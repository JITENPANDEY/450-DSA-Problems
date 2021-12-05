int findLIS(vector<vector<int>>& envelopes){
        int n = envelopes.size();
        vector<int>dp;
        dp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            int height = envelopes[i][1];
            if(height > dp.back()){
                dp.push_back(height);
            }else{
                int index = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
                dp[index] = height;
            }
        }
        return dp.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sort the enevelopes accoding to width and 
        //perform LIS on the height
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>&b){
            return a[0] < b[0] || (a[0]== b[0] && a[1] > b[1]);
        });
        return findLIS(envelopes);
        
    }