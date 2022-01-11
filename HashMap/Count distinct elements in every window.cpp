vector <int> countDistinct (int arr[], int n, int k)
{
    //code here.
    vector<int>ans;
    unordered_map<int, int> mp;
    
    int left = 0;
    for(int i=0;i<k;i++){
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());
    
    for(int right=k;right<n;right++){
        mp[arr[left]]--;
        mp[arr[right]]++;
        
        if(mp[arr[left]]==0) mp.erase(arr[left]);
        
        left++;
        
        ans.push_back(mp.size());
        
    }
    return ans;
}