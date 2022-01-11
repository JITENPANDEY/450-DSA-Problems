void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int pivot = nums[i];
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= pivot) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+ i + 1,nums.end());
    }.

    // explanation : https://www.nayuki.io/res/next-lexicographical-permutation-algorithm/next-permutation-algorithm.svg