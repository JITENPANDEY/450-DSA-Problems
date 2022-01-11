int countKdivPairs(int nums[], int n, int k)
{
    //code here
    unordered_map<int, int> mp;
    int ans =0;
    for(int i=0;i<n;i++){
        int rem1 = nums[i]%k;
        int rem2 = (rem1==0)?0 : rem1<0 ? -k-rem1 : k-rem1;
        int rem3 = -rem1;
        
        if(mp.find(rem2)!=mp.end()){
            ans+= mp[rem2];
        }else if(mp.find(rem3)!=mp.end()){
            ans+= mp[rem3];
        }
        mp[rem1]++;
    }
    return ans;
}