ll findSubarray(vector<ll> arr, int n ) {
  //code here
  unordered_map<ll,ll>mp;
  ll sum = 0;
  ll ans = 0;
  for(int i = 0; i < n; i++)
  {
      sum+=arr[i];
      if(sum==0) ans++;
      
      if(mp.find(sum) != mp.end())
          ans+=mp[sum];
      mp[sum]++;
  }
  return ans;
}