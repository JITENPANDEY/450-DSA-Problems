int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    while(low<high){
        int mid = (low+high)/2;
        bool isEvenLength = (high - mid)%2==0;
        if(nums[mid]==nums[mid-1]){
            if(isEvenLength){
                high = mid-2;
            }else{
                low = mid+1;
            }
        }
        else if(nums[mid]==nums[mid+1]){
            if(isEvenLength){
                low = mid+2;
            }else{
                high = mid-1;
            }
        }else{
            return nums[mid];
        }
    }
    cout<<"hello"<<endl;
    return nums[low];
}