class Solution {
public:
    static bool ifpalind(string s){
        int len = s.size();
        if(len == 0 || len == 1) return true;
        if(s[0] == s[len-1]){
            string substr = s.substr(1, len - 2);
            return Solution::ifpalind(substr);
        }else return false;
    }
    static int expend_single(const string& s, int& index){
        int step = 0;
        while(true){
            step++;
            if(index < step || s.size() - 1 < index + step) break;
            if(s[index-step] != s[index+step]) break;
            
        }
        return (2 * step - 1);
    }
    static int expend_double(const string& s, int& index){
        int step = 0;
        if (index + 1 >= s.size() || s[index]!=s[index+1])return false;
        while(true){
            step++;
            if(index < step || s.size() - 1 < index + step + 1) break;
            if(s[index-step] != s[index+step+1]) break;
            
        }
        return (2 * step);
    }
    
    string longestPalindrome(string s) {
        int longest_len = 0;
        string longest_str;
        int ssize = s.size();
        for (int i = 0; i < ssize; ++i){
            if((i+1) * 2 < longest_len) break;
            if((ssize - i)*2 < longest_len) break;
            int single_len = expend_single(s, i);
            int double_len = expend_double(s, i);
            if (longest_len < single_len){
                longest_len = single_len; 
                longest_str = s.substr(i - (single_len + 1)/2 + 1, single_len);
            }
            if (longest_len < double_len){
                longest_len = double_len;
                longest_str = s.substr(i - (double_len)/2 + 1, double_len);
            }
        }
        return longest_str;
    }
    
    string oldlongestPalindrome(string s) {
        int longest_len = 0;
        string longest_str;
        int ssize = s.size();
        
        for(int i = 0;i < ssize; ++i){
            string substr = s.substr(i, ssize - i);
            int end = substr.rfind(substr[0]);
            substr = substr.substr(0, end + 1);
            while(true){
                if(substr.size() <= longest_len) break;
                if(Solution::ifpalind(substr) == true){
                    longest_len = substr.size();
                    longest_str = substr;
                }else{
                    substr.pop_back();
                    end = substr.rfind(substr[0]);
                    substr = substr.substr(0, end - 1);
                }
            }
            
        }
        return longest_str;
    }
};
