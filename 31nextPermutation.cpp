class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int vector_size = nums.size();
        int start_index = 0;
        for(int i = vector_size - 1; i > 0; --i){
            if (nums[i] <= nums[i-1])continue;
            int left = i;
            int right = vector_size - 1;
            int middle = (left + right) / 2;
            while(left < right){
                if(nums[middle] <= nums[i-1]){
                    right = middle - 1;
                    middle = (left + right) / 2;
                }else if(nums[middle] > nums[i-1]){
                    left = middle + 1;
                    middle = (left + right) / 2;
                }
            }
            if(nums[middle] <= nums[i-1])middle--;
            int tmp = nums[middle];
            nums[middle] = nums[i-1];
            nums[i-1] = tmp;
            start_index = i;
            break;
        }
        for(int i = 0;i < (vector_size - start_index)/2; ++i){
            int tmp = nums[vector_size - i - 1];
            nums[vector_size - i - 1] = nums[i + start_index];
            nums[i + start_index] = tmp;
        }
        return;
    }
};
