//O(1) space coincise
vector<int> productExceptSelf(vector<int>& nums) {
    int n= nums.size();
    vector<int> ans(n,1);
    int leftProduct=1;
    int rightProduct=1;
    for(int i=0;i<n;i++){
        //first fill left product array
        ans[i] *= leftProduct;
        leftProduct *= nums[i];
        
        //update with rightProduct
        ans[n-i-1] *= rightProduct;
        rightProduct *= nums[n-i-1];    
    }
    return ans;
}

//O(1) space
vector<int> productExceptSelf(vector<int>& nums) {
    int n= nums.size();
    vector<int> ans(n,1);
    ans[0]=1;
    //fill from left to right and 
    //curr index will store the left product except that element from left only
    for(int i=1;i<n;i++) ans[i] = ans[i-1]*nums[i-1];
    
    //keep a variable that will store curr right product
    int right=1;
    for(int i=n-1;i>=0;i--){
    // final ans = product of left *  curr right
        ans[i] = ans[i]*right;
        right = right*nums[i];
    }
    
    return ans;
}