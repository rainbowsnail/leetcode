class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int i = 0;
        if(strs.size() == 0) return "";
        while(i < strs[0].size()){
            char n = strs[0][i];
            for(int j = 1; j < strs.size(); ++j){
                if(i >= strs[j].size() || n != strs[j][i]) return strs[0].substr(0, i);
            }
            ++i;
        }
        return strs[0];
    }
};
