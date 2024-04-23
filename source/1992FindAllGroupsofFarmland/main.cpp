#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
        vector<int> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(land[i][j] == 1){
                    int r1 = i, c1 = j;
                    int r2 = r1, c2 = c1;

                    res.clear();
                    res.push_back(r1);
                    res.push_back(c1);

                    while(r2 < m && land[r2][j] == 1){
                        r2++;
                    }
                    while(c2 < n && land[i][c2] == 1){
                        c2++;
                    }
                    for(int a = i; a < r2; a++){
                        for(int b = j; b < c2; b++){
                            land[a][b] = 0;
                        }
                    }
                    res.push_back(r2-1);
                    res.push_back(c2-1);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> land = {{1,0,0},{0,1,1},{0,1,1}};
    Solution sol;
    vector<vector<int>> res = sol.findFarmland(land);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}