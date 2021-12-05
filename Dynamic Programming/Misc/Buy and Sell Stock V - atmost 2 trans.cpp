  // EG: PRICES = [3,3,5,0,0,3,1,4]
    //     LEFT   = [0,0,2,2,2,2,2,3]
    //     RIGHT  = [2,2,4,4,4,1,0,0]
    //     SUM    = [2,2,6,6,6,3,2,3] 
	//     MAX PROFIT = 6
    int maxProfit(vector<int>& prices) {
       
        int n = prices.size();
        if(n<=1) return 0;
        
        int leftmin = prices[0], rightmax = prices[n-1];
        int left[n], right[n];
        left[0]=0, right[n-1]=0;
        
        for(int i=1;i<n;i++){
            int j = n-i-1;
            
            leftmin = min(prices[i], leftmin);
            left[i] = max(left[i-1], prices[i]-leftmin);
            
            rightmax = max(prices[j],rightmax);
            right[j] = max(right[j+1], rightmax - prices[j]);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            cout<<left[i]<<" "<<right[i]<<endl;
            ans = max(ans, left[i]+right[i]);
        }
        return ans;
    }