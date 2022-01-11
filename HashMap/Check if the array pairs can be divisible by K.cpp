bool canArrange(vector<int>& nums, int k) {
    // Code here.
    unordered_map<int, int> mp;
    for(auto &i : nums){
        int rem1 = i%k;
        int rem2 = (rem1==0)?0 : rem1<0 ? -k-rem1 : k-rem1;
        int rem3 = -rem1;
        
        if(mp.find(rem2)!=mp.end()){
            mp[rem2]--;
            if(mp[rem2]==0) mp.erase(rem2);
        }else if(mp.find(rem3)!=mp.end()){
            mp[rem3]--;
            if(mp[rem3]==0) mp.erase(rem3);
        }
        else{
            mp[rem1]++;
        }
    }
    return mp.size()==0;
}