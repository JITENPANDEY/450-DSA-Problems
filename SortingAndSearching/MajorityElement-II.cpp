 vector<int> majorityElement(vector<int>& nums) {
        int val1 = nums[0], val2=nums[0], count1=1, count2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==val1) count1++;
            else if(nums[i]==val2) count2++;
            else{
                if(count1==0){
                    count1=1;
                    val1=nums[i];
                }else if(count2==0){
                    count2=1;
                    val2=nums[i];
                }else{
                    count1--, count2--;
                }
            }
        }
        vector<int> ans;
        count1 = count2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == val1)
                count1++;
            else if (nums[i] == val2)
                count2++;
        }
        if (count1 > nums.size()/3)
            ans.push_back(val1);
        if (count2 > nums.size()/3)
            ans.push_back(val2);
        return ans;
    }