class Solution {
public:
    static bool isMatch(string s, string p) {
        //cout <<"s = "<<s<<"; p = "<< p <<endl;
        int si = 0, pi = 0;
        while( true ){
            if(si >= s.size() && pi >= p.size()) return true;
            else if(si >= s.size() && pi < p.size()) {
                if((p.size() - pi) % 2 != 0) return false;
                for (int i = 0; i * 2 + 1 + pi <  p.size(); ++i)
                    if (p[pi + i*2 + 1] != '*') return false;
                return true;
            }
            else if(si < s.size() && pi >= p.size()) return false;
            if(p.size() > pi + 1 && p[pi + 1]!= '*' || p.size() == pi + 1){
                if (s[si] != p[pi] && p[pi] != '.') return false;
                si++;pi++;
                continue;
            }
            //next charactor is *
            else{
                if(s[si] != p[pi] && p[pi] != '.'){
                    pi+=2;
                    continue;
                }else{
                    
                    if(Solution::isMatch(s.substr(si, s.size() - si), p.substr(pi + 2, p.size() - pi)))
                        return true;
                    for(int repeat = 1; si + repeat <= s.size() && (s[si + repeat -1] == p[pi] || p[pi] == '.'); ++repeat){
                        if(Solution::isMatch(s.substr(si + repeat, s.size() - si - repeat), p.substr(pi + 2, p.size() - pi - 2)))
                           return true;
                    }
                    return false;
                } 
            }            
        }
        return true;
    }
};
