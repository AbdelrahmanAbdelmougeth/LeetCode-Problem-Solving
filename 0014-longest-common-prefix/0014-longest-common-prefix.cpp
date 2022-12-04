class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
            return "";
        
        //get greedy and assume that the first string in string vector is the prefix
        string prefix = strs[0];
        for(int i=1; i<strs.size();i++){
            //if the string doesn't match then get less greedy
            while(prefix != strs[i].substr(0, prefix.size()))
                prefix = prefix.substr(0,prefix.size()-1);
        }
         return prefix;
    }
};