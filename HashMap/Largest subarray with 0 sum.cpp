int maxLen(vector<int>&A, int n)
{   
    // Your code here
    int ans = 0,sum=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(A[i]==0) ans = max(1,ans);
        if(sum==0) ans = max(ans, i+1);
        if(mp.find(sum)!=mp.end()){
            ans = max(ans, i-mp[sum]);
        }else
            mp[sum]=i;
    }
    return ans;
}

//
int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int ans = 0,sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(mp.find(sum)!=mp.end()){
                ans = max(ans, i-mp[sum]);
            }else
                mp[sum]=i;
        }
        return ans;
    }