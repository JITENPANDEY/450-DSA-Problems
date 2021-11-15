int lastStoneWeightII(vector<int>& arr) {
        // Your code goes here
	    int totalSum =0;
        int n = arr.size();
	    for(int i=0;i<n;i++)
	        totalSum+=arr[i];
	        
	   int sum = totalSum/2;
	   
	    bool dp[n+1][sum+1];
            
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                 if (j == 0)
               {
                   dp[i][j] = true;
               }
               else if (i == 0)
               {
                   dp[i][j] = false;
               }
                else if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] ||  dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
	    
	    int maxima = INT_MIN;
       for (int i = 0; i <= sum; i++)
       {
           if (dp[n][i])
           
           {
               maxima = max(maxima, i);
           }
           
       }
       return totalSum-2*maxima;
    }