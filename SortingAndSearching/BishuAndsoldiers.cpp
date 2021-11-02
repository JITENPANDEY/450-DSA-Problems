// Problem link : https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int arr[], int n, int power, int sum[]){
    int upper = upper_bound(arr, arr+n, power) - arr;
    return {upper, sum[upper-1]};
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;
    cin>>q;
    sort(arr, arr+n);
    int sum[n];
    int sm=0;
    for(int i=0;i<n;i++){
        sm +=arr[i];
        sum[i] = sm;
    }
    cout<<endl;
    while(q--){
        int power;
        cin>>power;
        vector<int>ans = solve(arr, n, power, sum);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;

}
