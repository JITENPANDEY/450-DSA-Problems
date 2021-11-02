vector<vector<int> > fourSum(vector<int> &nums, int target) {
    // Your code goes here
    vector<vector<int>> ans;
    int n = nums.size();
    if(n==0) return ans;
    
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){
            
            int new_target = target - nums[i]- nums[j];
            int left = j+1;
            int right = n-1;
            
            while(left<right){
                
                int sum  = nums[left]+nums[right];
                if(sum>new_target) right--;
                else if(sum<new_target) left++;
                
                else{
                    vector<int> quad;
                    quad.push_back(nums[i]);
                    quad.push_back(nums[j]);
                    quad.push_back(nums[left]);
                    quad.push_back(nums[right]);
                    ans.push_back(quad);
                    
                    while(left<right && nums[left]==quad[2])left++;
                    while(left<right && nums[right]==quad[3])right--;
                }
                  
            }
            while(j+1<n && nums[j]==nums[j+1]) j++;
        }
          while(i+1<n && nums[i]==nums[i+1]) i++;
    }
    return ans;
}