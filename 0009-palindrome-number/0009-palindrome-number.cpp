class Solution {
public:
    bool isPalindrome(int number) {    
        long reverse = 0;
        int temp = number;
        while (temp > 0)
        {
            reverse = reverse * 10 + temp % 10;;
            temp /= 10;
        }
        return(reverse == number);
        
    }
};