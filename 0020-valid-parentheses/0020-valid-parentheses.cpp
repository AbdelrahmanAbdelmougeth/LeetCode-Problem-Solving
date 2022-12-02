class Solution {
public:
    bool Matchc(char c1, char c2) {
        if (c1 == '[' && c2 == ']')
            return true;
        if (c1 == '{' && c2 == '}')
            return true;
        if (c1 == '(' && c2 == ')')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char> openning_parentheses_stack;

        for(int i=0; i<s.size(); i++){
           // push the openning parantheses to the stack 
           if(s[i] == '(' || s[i] == '[' || s[i] == '{')
              openning_parentheses_stack.push(s[i]);
            
           if(s[i] == ')' || s[i] == ']' || s[i] == '}')
           {
               if(!openning_parentheses_stack.size())
                   return false;
               else if(Matchc(openning_parentheses_stack.top(), s[i]))
                       openning_parentheses_stack.pop();
               else
                   return false;
           }
        }
        return !openning_parentheses_stack.size();
    }
};