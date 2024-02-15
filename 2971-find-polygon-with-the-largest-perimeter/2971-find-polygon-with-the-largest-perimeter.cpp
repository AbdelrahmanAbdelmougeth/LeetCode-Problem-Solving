class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        if(nums.size() <= 2)
            return -1;
        
        //first we sort the array O(n log n)
        sort(nums.begin(), nums.end(), greater<int>());
        
        //I used the prefix sum to speed the things alittle bit O(n)
        long long prefix_sum_of_nums = 0;
        for(auto x : nums)
            prefix_sum_of_nums += x;
        
        //let's go greedy 
        //Assume that the largest given side is the longest side
        //check for the polygon condition 
        //if it's sutisfied then that's a polygon
        //if not let's go less greedy
        for(int i=0; i<nums.size(); i++){
            long long sum_of_all_sides_but_the_longest = prefix_sum_of_nums - nums[i];
            if(sum_of_all_sides_but_the_longest > nums[i] && nums.size() - i >= 3)
                return prefix_sum_of_nums;
            else
                prefix_sum_of_nums -= nums[i];
        }
        //all greedy solutions failed and no polygon can be created
        return -1;
    }
};