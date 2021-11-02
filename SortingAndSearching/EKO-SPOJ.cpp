#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool isSufficient(ll *height, ll n, ll m, ll mid){
  ll wood =0;
  for(ll i=0;i<n; i++){
      if(height[i]>mid)
            wood+=height[i]-mid;
      if(wood>=m)
      	return true;
  }
  return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  ll n, m;
  cin>>n>>m;
  ll height[n];
  ll maxHeight = 0;
  for(ll i=0;i<n;i++){
    cin>>height[i];
    maxHeight = max(maxHeight, height[i]);
  }

  ll low =0, high = maxHeight, ans=0;
  while(low<=high){
    ll mid = low + (high - low)/2;
    if(isSufficient(height,n, m, mid)){
      ans = mid;
      low = mid+1;
    }
    else
      high = mid-1;
  }
  cout<<ans<<endl;
  return 0;
}