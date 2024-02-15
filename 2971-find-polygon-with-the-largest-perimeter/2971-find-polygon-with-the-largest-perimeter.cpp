class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        if(nums.size() <= 2)
            return -1;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        long long prefix_sum_of_nums = 0;
        for(auto x : nums)
            prefix_sum_of_nums += x;
        
        for(int i=0; i<nums.size(); i++){
            long long sum_of_all_sides_but_the_longest = prefix_sum_of_nums - nums[i];
            if(sum_of_all_sides_but_the_longest > nums[i] && nums.size() - i >= 3)
                return prefix_sum_of_nums;
            else
                prefix_sum_of_nums -= nums[i];
        }
        return -1;
    }
};