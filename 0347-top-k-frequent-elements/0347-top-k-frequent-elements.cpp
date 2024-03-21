class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> num_frequent;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> res;
        
        for(auto x: nums)
            num_frequent[x]++;
        
        for(auto x: num_frequent){
            bucket[x.second].push_back(x.first);
            cout<<x.first<<" "<<x.second<<'\n';
        }
            
        
        for(int i=bucket.size()-1; i>=0; i--){
            if (res.size() >= k) {
                break;
            }
            if (!bucket[i].empty()) {
                for(auto x: bucket[i])
                    res.push_back(x);
            }
        }
        
        return res;
    }
};