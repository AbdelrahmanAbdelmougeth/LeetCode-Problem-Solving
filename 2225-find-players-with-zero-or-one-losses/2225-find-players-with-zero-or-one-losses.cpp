class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        #define winner 0
        #define looser 1
        
        typedef struct{
            int win_times;
            int loose_times;
        }player;
        
        vector<vector<int>>answer(2); //initialize the answer vector
        unordered_map<int, player>players_win_loose_times;
        
        for(int i=0; i<matches.size(); i++){
            if(players_win_loose_times.find(matches[i][winner]) == players_win_loose_times.end()){
                players_win_loose_times[matches[i][winner]] = {1,0};
            }
            else{
                players_win_loose_times[matches[i][winner]].win_times++;
            }
            if(players_win_loose_times.find(matches[i][looser]) == players_win_loose_times.end()){
                players_win_loose_times[matches[i][looser]] = {0,1};
            }
            else{
                players_win_loose_times[matches[i][looser]].loose_times++;
            }
            
        }
        
        for(auto x : players_win_loose_times){
            if(x.second.loose_times == 0)
                answer[0].push_back(x.first);
            if(x.second.loose_times == 1)
                answer[1].push_back(x.first);
        }
        
        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());
        
        return answer;
    }
};