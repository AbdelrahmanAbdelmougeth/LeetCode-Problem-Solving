class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int left_pointer = 0, right_pointer = height.size() - 1;
        while(left_pointer < right_pointer){
            int minHeight = min(height[left_pointer], height[right_pointer]);
            int length = right_pointer - left_pointer;
            maxArea = max(maxArea, (minHeight*length));
            if(height[left_pointer] < height[right_pointer]){
                left_pointer++;
            }else{
                right_pointer--;
            }
        }
        return maxArea;
    }
};