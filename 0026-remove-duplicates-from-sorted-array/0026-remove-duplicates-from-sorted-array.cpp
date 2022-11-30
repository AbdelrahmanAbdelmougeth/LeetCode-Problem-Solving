class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums.at(i) != nums.at(flag-1))
            {nums.at(flag) = nums.at(i); flag++;}   
        }
        return flag;
    }
};