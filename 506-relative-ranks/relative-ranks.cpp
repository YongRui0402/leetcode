class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> res(score.size());
        vector<int> rank(score.size());
        rank = score;
        sort(rank.begin(), rank.end(), greater<int>());
        for(int i = 0; i < score.size(); i++){
            if(score[i] == rank[0]){
                res[i] = "Gold Medal";
            }else if(score[i] == rank[1]){
                res[i] = "Silver Medal";
            }else if(score[i] == rank[2]){
                res[i] = "Bronze Medal";
            }else{
                res[i] = to_string( find(rank.begin(), rank.end(), score[i]) - rank.begin() + 1);
            }
        }
        return res;
    }
};