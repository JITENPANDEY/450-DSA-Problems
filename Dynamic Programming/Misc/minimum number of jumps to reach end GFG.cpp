int minJumps(int nums[], int n){
        // Your code here
        int currReach=0;
        int maxReach =0;
        int jumps=0;
        if(n==1) return 0;
        
        if(nums[0]==0) return -1;
        
        for(int i=0;i<n-1;i++){
            
            if(maxReach<nums[i]+i){
                maxReach = nums[i]+i;
                
                //cout<<"maxReach="<<maxReach<<endl;
            }
            
            if(nums[i]==0 && maxReach==nums[i]+i) return -1;
            //we will not take any jump if my currReach is less than the max reach
            // we will only take  jump if 
            if(i==currReach){
                currReach = maxReach;
                jumps++;
                //cout<<"currReach = "<<currReach<<endl;
            }
                
        }
        return jumps;
    }