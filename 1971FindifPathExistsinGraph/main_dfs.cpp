#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);

    }
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int source, int destination){
        if(source == destination){
            return true;
        }
        visited[source] = true;
        for(auto i:graph[source]){
            if(!visited[i]){
                if(dfs(graph, visited, i, destination)){
                    return true;
                }
            }
        }
        return false;
    }
    
};
int main(){
    Solution sol;
    // vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    // cout<<sol.validPath(6, edges, 0, 5)<<endl;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout<<sol.validPath(3, edges, 0, 2)<<endl;
    return 0;
}