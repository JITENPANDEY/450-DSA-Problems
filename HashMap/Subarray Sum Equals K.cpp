int subarraySum(vector<int>& arr, int K) {
    unordered_map<int, int> preSumFreq;
    preSumFreq[0]=1;
    int sum =0, ans =0;
    for(int i=0;i<arr.size();i++){
        sum +=arr[i];
        ans += preSumFreq[sum-K];
        preSumFreq[sum]++;
    }
    return ans;
}