class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator cur = nums.begin();
        while(cur != nums.end() && cur + 1 != nums.end()){
            if(*cur == *(cur+1))cur = nums.erase(cur);
            else cur++;
        }
        return nums.size();
    }
};
