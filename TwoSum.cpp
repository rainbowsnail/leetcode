class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for(int i = 0; i < nums.capacity(); ++i)		        
		for(int j = 0; j < nums.capacity(); ++j){
			if (nums[i] + nums[j] == target){
				vector<int> result;
				result.clear();
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
};
