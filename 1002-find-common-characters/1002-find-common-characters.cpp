class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char, int>> word_char_count(words.size());
        for(int i=0; i<words.size(); i++)
            for(char c : words[i])
                word_char_count[i][c]++;
        
        vector<string> res;
        
        unordered_set<char> checked;
        for(char c : words[0]){
            if(checked.find(c) == checked.end())
                checked.insert(c);
            else
                continue; 
            int min_char_count = INT_MAX;
            for(int i=0; i<word_char_count.size(); i++){
                if(word_char_count[i].find(c) != word_char_count[i].end()){
                    min_char_count = min(min_char_count, word_char_count[i][c]);
                }else{
                    min_char_count = 0;
                }
            }
            while(min_char_count){
                string str;
                res.push_back(str+=c);
                min_char_count--;
            }
                
        }
        
        return res;        
    }
};