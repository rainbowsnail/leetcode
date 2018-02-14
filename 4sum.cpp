class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); ++i)
        for(int j = i + 1; j < nums.size(); ++j){
            int l = j + 1;
            int r = nums.size() - 1;
            int sum = target - nums[i] - nums[j];
            while(l < r){
                if(nums[l] + nums[r] == sum){
                    res.insert(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                    while(l < r && nums[l] == nums[l + 1]) ++l;
                    while(l < r && nums[r] == nums[r - 1]) --r;
                    ++l;--r;
                 }else if(nums[l] + nums[r] < sum) ++l;
                else --r;
            }
        }
        return vector<vector<int>> (res.begin(),res.end());
    }
};
