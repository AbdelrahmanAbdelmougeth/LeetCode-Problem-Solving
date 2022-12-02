class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        //create the 2D vector
        int numCols = ceil(s.size() / (2 * numRows - 2.0)) * (numRows - 1);        
        vector<vector<char>> zig_zag(numRows, vector<char>(numCols, ' '));
        
        //fill the 2D vector in zig zag form
        int str_index = 0;
        int curr_row = 0, curr_col = 0;
        
        //as long as the string is not finished we repeat the cycle
        while(str_index < s.size()){
            //make a cycle
            
            //move down until we reach the number of rwos or the string finishes
            while(str_index < s.size() && curr_row < numRows){
                zig_zag[curr_row][curr_col] = s[str_index];
                str_index++;
                curr_row++;    
            }
            curr_row -= 2;
            curr_col++;
            //move up in diagonal until the string finishes or we reached the first row
            while(str_index < s.size() && curr_row > 0){
                zig_zag[curr_row][curr_col] = s[str_index];
                str_index++;
                curr_row--;
                curr_col++;
            }
                   
        }
        

        string zig_zag_str = "";
        for(int i=0; i < numRows; i++)
            for(int j=0; j<numCols; j++)
                if(zig_zag[i][j] != ' ')
                    zig_zag_str += zig_zag[i][j];    
        
        return zig_zag_str;
    }
};