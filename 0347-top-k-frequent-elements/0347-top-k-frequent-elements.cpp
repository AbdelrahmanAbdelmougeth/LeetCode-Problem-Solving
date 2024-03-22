struct NumFrequent {
    int num;
    int frequent;
 
    // this will used to initialize the variables
    // of the structure
    NumFrequent(int num, int frequent)
        : num(num)
        , frequent(frequent)
    {}
    
    bool operator<(const NumFrequent& other) const {
        // Compare based on priority (lower value has higher priority)
        return frequent < other.frequent;
    }
};

/*
// this is an structure which implements the
// operator overloading
struct CompareFrequent {
    bool operator()(num_frequent const& f1, num_frequent const& f2)
    {
        // return "true" if "f1" is ordered
        // before "f2", for example:
        return f1.frequent < f2.frequent;
    }
};
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_frequent;
        vector<int> res;
        
        for(auto x: nums)
            num_frequent[x]++;
        
        priority_queue<NumFrequent> pQ;
        for(auto x: num_frequent)
            pQ.push(NumFrequent(x.first, x.second));
        
        for(int i=0; i<k; i++){
            res.push_back(pQ.top().num);
            pQ.pop();
        }
        
        return res;
        
        /*
        // bucket based solution
        unordered_map<int, int> num_frequent;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> res;
        
        for(auto x: nums)
            num_frequent[x]++;
        
        for(auto x: num_frequent){
            bucket[x.second].push_back(x.first);
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
        */
    }
};