#include<bits/stdc++.h>
using namespace std;
double sqrt(int n){
  double low =0, high=n;
  double ans=0;
  while((high-low) > 1e-6){

    double mid = (low+high)/2.0;
    if(mid*mid>n)
        high=mid;
    else{
        low= mid;
    }
  }
  return low;
}
int main(){
  cout<<sqrt(120);
}