class Solution {
public:
    //I V X L C D M
    int romanToInt(string s) {
        map<char, int> c2i;
        c2i['I'] = 1;
        c2i['V'] = 5;
        c2i['X'] = 10;
        c2i['L'] = 50;
        c2i['C'] = 100;
        c2i['D'] = 500;
        c2i['M'] = 1000;
        
        int result = 0;
        for(int i = 0; i< s.size() ; ++i){
            if(i == s.size() - 1){
                result += c2i[s[i]];
                break;
            }
            if(c2i[s[i + 1]] > c2i[s[i]]){
                result += c2i[s[i+1]] - c2i[s[i]];
                i++;
            }else result += c2i[s[i]];
        }
        return result;
    }
};
