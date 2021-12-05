vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
  
  vector<long long int> ans(n,1);
  long long int leftProduct=1;
  long long int rightProduct=1;
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
//first fill the output array with left product
//  then update the out put array with right product

//  Op[i]= Op[i-1]*product
//  product *= nums[i];

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