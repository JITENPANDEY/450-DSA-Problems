int maxHeight(int height[],int width[],int length[],int size)
    {
        //Your code here
        vector<vector<int>>cuboids; //{length, width, height}
        for(int i=0;i<size;i++){
            
            //consider height[i] and height and interchange length and breadth
            cuboids.push_back({max(width[i], length[i]), min(width[i], length[i]), height[i]});
            
            //fix  width as height and interchange length and height
            cuboids.push_back({max(height[i], length[i]), min(height[i], length[i]), width[i]});
            
            //fix  length as height and interchange breadh and height
            cuboids.push_back({ max(height[i], width[i]), min(height[i], width[i]), length[i]});
        }
        sort(cuboids.begin(), cuboids.end(), [](vector<int>&a, vector<int>&b){
            return a[0]*a[1]<b[0]*b[1];
        });
        
        // for(auto i : cuboids){
        //     cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        // }
        int n=cuboids.size();
        vector<int> dp(n,0);
        for (int i=0;i<n;i++){
            dp[i]=cuboids[i][2];
            for (int j=0;j<i;j++){
                if (cuboids[j][0]<cuboids[i][0] && cuboids[j][1]<cuboids[i][1]){
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }