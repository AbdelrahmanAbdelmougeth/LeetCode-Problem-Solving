class Solution {
public: 
    int max(int a, int b){
        return a > b ? a : b;
    }
    
    int lengthOfLongestSubstring(string s) {
        //starting the substring with size of 0
        int substring_starting_index = 0, substring_ending_index = 0, 
        substring_length = 0;
        
        //to check if there is a duplicate in characters
        unordered_set<char> charSet;
        
        while(substring_ending_index < s.size()){
            if(charSet.find(s[substring_ending_index]) == charSet.end()){
                charSet.insert(s[substring_ending_index]);
                substring_ending_index++;
                substring_length = max(substring_length, charSet.size());
            }else{
                charSet.erase(s[substring_starting_index]);
                substring_starting_index++;
            }
        }
        return substring_length;
    }
};