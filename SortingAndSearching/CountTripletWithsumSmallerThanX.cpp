long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long count=0;
	    sort(arr, arr+n);
	    for(int i=n-1;i>=0;i--){
	        int j=0;
	        int k=i-1;
	        while(j<k){
	            long long trySum = arr[i]+arr[j]+arr[k];
	            if(trySum<sum){
	                //cout<<trySum<<endl;
	                count+=k-j;
	                j++;
	            }
	                
	            else if(trySum>=sum)
	                k--;
	        }
	    }
	    return count;
	}