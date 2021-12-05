bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        
        //we will check the the maximum index we can reach from the the current index
        for(int i=0;i<n;i++){
            if(reachable<i) // if curent index crosses the maximum reachable postion the e cannot reach to the end
                return false;
            
            reachable = max(reachable, i+nums[i]);
        }
        return true;
    }