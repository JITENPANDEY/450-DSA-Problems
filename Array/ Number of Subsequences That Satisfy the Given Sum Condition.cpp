int mod = 1e9+7;
int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int>pow2(nums.size()+1,1);
    for(int i=1;i<=nums.size();i++)
    {
        pow2[i]=(2*pow2[i-1])%mod;
    }
    
    int ans =0;
    int l =0, r = nums.size()-1;
    while(l<=r)
    {
        if(nums[l]+nums[r]<=target)
        {
            ans=(ans+pow2[r-l])%mod;
            l++;
        }
        else
            r--;
    }
    return ans;
}