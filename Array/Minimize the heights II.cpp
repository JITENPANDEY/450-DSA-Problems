int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int ans = arr[n - 1] - arr[0];
        int maxi = arr[n - 1];
        int mini = arr[0];

        for(int i=1;i<n;i++){
          if(arr[i]>=k){
            maxi = max(arr[n-1]-k, arr[i-1]+k);
            mini = min(arr[0]+k, arr[i]-k);
            
            //cout<<maxi<<" - "<<mini<<" = "<<maxi-mini<<endl;
            ans = min(ans, maxi-mini);
          } 
           
        }
        return ans;
    }