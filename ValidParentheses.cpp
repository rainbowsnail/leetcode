class Solution {
public:
    bool isValid(string s){
        string strstack = "";
        int s_i = 0;
        while(s_i < s.size()){
            strstack += s[s_i++];
            bool flag = true;
            while(strstack.size() >= 2 && flag == true){
                if(strstack[strstack.size() - 2] == '(' && strstack[strstack.size() - 1] == ')' ||
                   strstack[strstack.size() - 2] == '[' && strstack[strstack.size() - 1] == ']' ||
                   strstack[strstack.size() - 2] == '{' && strstack[strstack.size() - 1] == '}')
                strstack = strstack.substr(0, strstack.size() - 2);
                else flag = false;
            }  
              
        }
        if(strstack.size() == 0) return true;
        return false;
    }
};
