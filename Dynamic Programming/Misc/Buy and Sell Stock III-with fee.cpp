int maxProfit(vector<int>& prices, int fee) {
        int obsp = -1*prices[0]; //oldBoughtStatePrice
        int ossp = 0; //oldSellingStateProfit
        for(int i=1;i<prices.size();i++){
            int nbsp =0; //newBoughtStatePrice
            int nssp =0; //newSellingStateProfit
            
            if(ossp - prices[i]>obsp){
                nbsp = ossp - prices[i];
            }else{
                nbsp =  obsp;
            }
            
            if(prices[i] + obsp - fee>ossp){
                nssp = prices[i] + obsp - fee;
            }else{
                nssp = ossp;
            }
            obsp = nbsp;
            ossp = nssp;  
        
            //cout<<ossp<<endl;
        }
        return ossp;
    }
    
//     int maxProfit(vector<int>& p, int fee) {
//         int n = p.size();
//         if (n < 2) return 0;
//         vector<int> hold(n, 0), sold(n, 0);
//         hold[0] = -p[0];
//         for (int i = 1; i < n; i++) {
//             hold[i] = max(hold[i - 1], sold[i - 1] - p[i]);
//             sold[i] = max(sold[i - 1], hold[i - 1] - fee + p[i]);
//         }

//         return sold[n - 1];
//     }