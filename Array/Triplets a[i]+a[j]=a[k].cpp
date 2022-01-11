vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> ans;
	if(nums.size()<3) return ans;
	
	sort(nums.begin(), nums.end(), greater<int>());
	int i=0;
	while(i<n-2){
		int j=i+1;
		int k=n-1;
		int a= nums[i];
		while(j<k){
			if(nums[i] == nums[j] + nums[k]){
				vector<int> v;
				v.push_back(nums[i]);
				v.push_back(nums[j]);
				v.push_back(nums[k]);
				ans.push_back(v);
				
				int x = nums[j];
				int y = nums[k];
				while(j<n && nums[j]==x) j++;
				while(k>=0 && nums[k]==y) k--;
			}
			
			else if(nums[i] < nums[j] + nums[k] ) k--;
			else j++;
		}
		while(i<n && nums[i]==a) i++;
	}
	return ans;
        
    }