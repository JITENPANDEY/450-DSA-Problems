static long getSum(vector<int>nums, int d)
    {
        long sum = 0;
        for(auto i : nums)
            sum+=ceil((double)i/d);
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        
        while(start<=end)
        {
            int mid = start + (end - start)/2;
            if(getSum(nums,mid)>threshold)
            {
                start = mid+1;
                
            }    
            else
                end = mid-1;        
        }
        return start;
    }