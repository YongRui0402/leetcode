class Solution {
private:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> count;
    unordered_map<int, int> ans;
    void dfs(int node, int parent){
        for(int child: graph[node]){
            if(child == parent) continue;
            dfs(child, node);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
        count[node]++;
    }
    void dfs2(int node, int parent){
        for(int child: graph[node]){
            if(child == parent) continue;
            ans[child] = ans[node] - count[child] + count.size() - count[child];
            dfs2(child, node);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        vector<int> res;
        for(int i = 0; i < n; i++){
            res.push_back(ans[i]);
        }
        return res;
    }
};