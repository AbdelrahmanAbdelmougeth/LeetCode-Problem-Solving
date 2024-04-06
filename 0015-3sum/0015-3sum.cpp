class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            int left_pointer = i+1, right_pointer = nums.size() - 1;
            while(left_pointer < right_pointer){
                if(nums[i] + nums[left_pointer] + nums[right_pointer] > 0){
                    right_pointer--;
                    continue;
                }else if(nums[i] + nums[left_pointer] + nums[right_pointer] < 0){
                    left_pointer++;
                    continue;
                }else{
                    st.insert({nums[i], nums[left_pointer], nums[right_pointer]});
                    left_pointer++; right_pointer--;
                }
            }
        }
        for(auto x: st)
           ans.push_back(x);
        
        return ans;
    }
};