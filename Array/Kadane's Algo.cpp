long long maxSubarraySum(int arr[], int n){
        // Your code here
        int currSum =0;
        int finalSum = INT_MIN;
        for(int i=0;i<n;i++){
            currSum = max(arr[i] , currSum+arr[i]);
            finalSum = max(currSum,finalSum);
        }
        return finalSum;
        
    }