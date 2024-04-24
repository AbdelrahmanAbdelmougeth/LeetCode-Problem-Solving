struct index_height{
    int index;
    int height;
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<index_height> ind_h;
        int n = heights.size();
        int max_area = INT_MIN;
        int start_index;
        for(int i=0; i<n; i++){
            start_index = i;
            while(ind_h.size() && ind_h.top().height > heights[i]){
                max_area = max(max_area, ind_h.top().height * (i - ind_h.top().index));
                start_index = ind_h.top().index; 
                ind_h.pop();
            }
            ind_h.push({start_index, heights[i]});
        }
        while(ind_h.size()){
            max_area = max(max_area, ind_h.top().height * (n - ind_h.top().index));
            ind_h.pop();
        }
        return max_area;
    }
};