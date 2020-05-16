class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        std::string_view ss(s);
        int word_cnt = words.size();
        if (word_cnt == 0) return ans; 
        int word_size = words[0].size();
        
        std::unordered_map<std::string_view, int> word_map;
        //for(auto each_word :  words){
        for (const string& each_word : words){
            ++word_map[string_view(each_word)];
        }
        
        int string_size = s.size();

        for (int i = 0; i<= string_size - word_cnt * word_size; ++i){
            int match = 0;
            std::unordered_map<std::string_view, int> seen;
            for (int j = 0; j < word_cnt; ++j){
                string_view cur_pos = ss.substr(i + j* word_size, word_size);
                if (word_map.find(cur_pos) != word_map.end()){
                    ++seen[cur_pos];
                    if (seen[cur_pos]>word_map[cur_pos]){
                        break;
                    }                        
                    match++;
                }
            
            }
            if (match == word_cnt)
                ans.push_back(i);
        }
        return ans;
    }
    
};
