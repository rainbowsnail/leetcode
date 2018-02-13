class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result;
        int diff = INT_MAX;
        for(int k = 0; k < nums.size(); ++k){
            int sum = target-nums[k];
            int left = k + 1;
            int right = nums.size() - 1;
            while(left < right){     
                int curSum = nums[left] + nums[right] + nums[k];
                if(abs(target - curSum) < diff){
                    diff = abs(target - curSum);
                    result = curSum;
                }
                if(nums[left] + nums[right] > sum) right--;
                else left++;
            }
        }
        return result;
    }
};
