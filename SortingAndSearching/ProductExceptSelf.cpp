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