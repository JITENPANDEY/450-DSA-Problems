#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll maxSum(vector<ll>&arr1, vector<ll>&arr2){
  ll i=0, j=0;
  ll maxsum =0;
  ll sum1=0, sum2=0;
  while(i<arr1.size() && j<arr2.size()){
      if(arr1[i]>arr2[j]){
          sum2+=arr2[j];
          j++;
      }else if(arr1[i]<arr2[j]){
          sum1+=arr1[i];
          i++;
      }else{
          maxsum += max(sum1, sum2)+arr1[i];
          sum1=0;
          sum2=0;
          i++, j++;
      }  
  }
  if(i<arr1.size()){
      while(i<arr1.size())
        sum1+=arr1[i++];
  }
  if(j<arr2.size()){
      while(j<arr2.size())
        sum2+=arr2[j++];
  }
  maxsum+=max(sum1, sum2);
  return maxsum;
  
}
int main(){
  vector<ll> arr1 = {3 ,5 ,7 ,9 ,20 ,25 ,30 ,40 ,55 ,56 ,57 ,60 ,62};
  vector<ll> arr2 = {1 ,4 ,7 ,11 ,14 ,25 ,44 ,47 ,55 ,57 ,100};
  ll ans = maxSum(arr1, arr2);
  cout<<ans<<endl;
}