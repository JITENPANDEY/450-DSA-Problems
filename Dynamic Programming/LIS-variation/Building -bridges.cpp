#include<bits/stdc++.h>
using namespace std;

// int non_overlapping_bridges(vector<vector<int>> &temp,int n)
// {
//     sort(temp.begin(), temp.end(), [](vector<int> &a, vector<int>&b){
//         if(a[0]!=b[0])
//             return a[0]<b[0];
//         else
//             return a[1]<b[1];
//     });
//     vector<int>dp(temp.size(), 1);
//       int ans = 0;
//       for(int i=0;i<temp.size();i++){
//           int currMax = 1;
//           for(int j=0;j<i;j++){
//               if(temp[i][1]>temp[j][1]){
//                   dp[i] = max(dp[i], dp[j]+1);
//                   currMax = max(dp[i], currMax);
//               }
//           }
//           ans = max(ans, currMax);
//       }
//       return ans;
// }

int non_overlapping_bridges(vector<vector<int>> &temp,int n)
{
  sort(temp.begin(), temp.end(), [](vector<int> &a, vector<int>&b){
        if(a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]<b[1];
    });
	vector<int>dp;
    dp.push_back(temp[0][1]);
    for(int i=1;i<temp.size();i++){
        if(temp[i][1]>dp.back())
            dp.push_back(temp[i][1]);
        else{
            int index = lower_bound(dp.begin(), dp.end(), temp[i][1]) - dp.begin();
            dp[index] = temp[i][1];
        }
    }
    return dp.size();
}

int main()
{
	int n ;
	cin>>n;
	vector<vector<int>> temp;
	while(n--){
	    int a, b;
	    cin>>a>>b;
	    temp.push_back({a, b});
	}
	cout<<non_overlapping_bridges(temp,n)<<endl;
	return 0;
}
