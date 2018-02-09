class Solution {
public:
    static int lengthOfLongestSubstringWithFirstChar(string s) {
        if (s.empty() == true) return 0;
        string newstr = s.substr(1, s.size()-1);
        int len = newstr.find_first_of(s[0]);
        string substr = s.substr(1, len);
        return 1 + Solution::lengthOfLongestSubstringWithFirstChar(substr);
    }
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        for(int i = 0;i< s.size();++i){
            string substr = s.substr(i, s.size()-i);
            int cur = Solution::lengthOfLongestSubstringWithFirstChar(substr);
            if (cur > longest) longest = cur;
        }
        return longest;
    }
};
