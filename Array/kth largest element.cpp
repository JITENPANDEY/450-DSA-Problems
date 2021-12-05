 int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        
        priority_queue<int, vector<int>, greater<int>>minHeap;
       for(int i=0;i<nums.size();i++)
       {
           minHeap.push(nums[i]);
           if(minHeap.size()>k)
           minHeap.pop();
       }
       return minHeap.top();
    }