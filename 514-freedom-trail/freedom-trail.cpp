class Solution {
    int ring_size;
    unordered_map<char,vector<int>> mp;
    int solve(string &key, int idx, int pos, vector<vector<int>>& dp){
        if(idx == key.size()){
            return 0; //end of key
        }
        if(dp[idx][pos] != -1){
            return dp[idx][pos];
        }
        int steps = INT_MAX;
        int key_value = key[idx];
        
        //going to all indexes
        for(int i = 0; i < mp[key_value].size(); i++){
            int new_pos = mp[key_value][i];
            int taken = solve(key,idx+1,new_pos,dp);
            
            int dis = pos-new_pos,sqg_flag=(pos>new_pos)?1:-1;

            
            if(dis*sqg_flag*2<ring_size) //clockwise
                steps = min(steps,1+dis*sqg_flag+taken);
            else//anticlockwise
                steps = min(steps,1+ring_size-dis*sqg_flag+taken);
        }
        return dp[idx][pos] = steps;
    }
public:
    int findRotateSteps(string& ring, string& key) {
        ring_size = ring.size();
        for(int i = 0; i < ring_size; i++){
            mp[ring[i]].push_back(i); 
        }

        vector<vector<int>> dp(key.size(),vector<int>(ring.size(),-1));
        return solve(key,0,0,dp);
    }
};