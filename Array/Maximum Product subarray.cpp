	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    if(n==1) return arr[0];
	    
	    long long curr_max = arr[0];
	    long long curr_min = arr[0];
	    long long prev_max = arr[0];
	    long long prev_min = arr[0];
	    long long ans = arr[0];
	    for(int i=1;i<n; i++){
	        curr_max = max({(long long)arr[i], (long long)arr[i]*prev_max, (long long)arr[i]*prev_min});
	        curr_min = min({(long long)arr[i], (long long)arr[i]*prev_max, (long long)arr[i]*prev_min});
	        ans = max(ans, curr_max);
	        
	        prev_max = curr_max;
            prev_min = curr_min;
	    }
	    return ans;
	}