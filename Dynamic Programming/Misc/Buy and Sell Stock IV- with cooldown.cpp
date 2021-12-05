int maxProfit(vector<int>& prices) {
        int obsp = -prices[0];
        int ossp = 0;
        int ocsp = 0;
        for(int i=1;i<prices.size();i++){
            int nbsp = max(obsp, ocsp - prices[i]);
            int nssp = max(ossp, prices[i] + obsp);
            int ncsp = max(ocsp, ossp);
            
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
        return ossp;
    }