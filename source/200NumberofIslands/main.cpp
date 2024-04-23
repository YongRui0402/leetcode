#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
};
int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','1','1'},
        {'1','1','0','1','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout<<sol.numIslands(grid)<<endl;

    return 0;
}