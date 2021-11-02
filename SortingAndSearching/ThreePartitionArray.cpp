#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
  vector<ll> arr = {7,2,4,1,5};
  int a =3, b=5;
  int low = 0;
  int high = arr.size()-1;
  int mid = 0;
  while(mid<=high){
      if(arr[mid]<a){
          swap(arr[mid++], arr[low++]);
      }else if(arr[mid]>b){
          swap(arr[mid], arr[high--]);
      }else{
          mid++;
      }
  }
  for(auto i : arr) cout<<i<<" ";
}

//dutch-national-flag algorithm