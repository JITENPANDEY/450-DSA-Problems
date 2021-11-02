#include<bits/stdc++.h>
using namespace std;
int sqrt(int n){
  int low =0, high=n;
  int ans=0;
  while(low<=high){

    int mid = (low+high)/2;
    if(mid*mid>n)
      high=mid-1;
    else if(mid*mid<n){
        ans = mid;
        low= mid+1;
    }
    else
        return mid;
  }
  return ans;
}
int main(){
  cout<<sqrt(1);
}

