class Solution {
public:
   int mySqrt(int x) {
       if(x==0 || x==1)
           return x;
       
       int left = 0, right = x / 2; 
       int sqr;
       while(left <= right){
           long mid = (left + right) / 2;
           
           if(mid * mid == x)
               return mid;
           
           if(mid * mid <= x){
               left = mid + 1;
               sqr = mid;
           }else{
               right = mid -1;
           }   
       }
       return sqr;
   }
};