#include<bits/stdc++.h>
using namespace std;
bool canBePlaced(int position[], int n , int cows, int mid){
  int lastPlaced = position[0];
  int cowsPlaced=1;
  for(int i=1;i<n;i++){
    if(position[i]-lastPlaced >= mid){
        cowsPlaced++;
        if(count==cows)
            return true;
        lastPlaced = position[i];
    }

  }
  return false;
}
int largestMinimumDistance(int position[], int n , int cows){
  sort(position, position+n);
  int low = 1, high = position[n-1];
  int ans=0;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(canBePlaced(position, n, cows ,mid)){
      ans = mid;
      low = mid+1;
    }else
      high = mid-1;
  }
  return ans;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n, cows;
    cin>>n>>cows;
    int position[n];
    for(int i=0;i<n;i++) cin>>position[i];

    cout<<largestMinimumDistance(position, n, cows);
  }
  
}