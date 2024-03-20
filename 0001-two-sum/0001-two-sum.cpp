class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index;
        vector<int> ans(2);
        for(int i=0; i<nums.size(); i++){
            
            if(num_index.find(target - nums[i]) != num_index.end()){
                ans[0] = num_index[target - nums[i]];
                ans[1] = i;
                break;
            }
            else{
                num_index[nums[i]] = i;
            }
        }
        return ans;
    }
};