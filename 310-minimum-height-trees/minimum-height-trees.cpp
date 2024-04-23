#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n==1){
            ans={0};
        }
        else{
            vector<vector<int>> arr(n);
            vector<int>deg(n,0);
            for(auto edge:edges){
                arr[edge[0]].push_back(edge[1]);
                arr[edge[1]].push_back(edge[0]);
                deg[edge[0]]+=1;
                deg[edge[1]]+=1;
            }

            queue<int> q;
            for(int i=0;i<n;i++){
                if(deg[i]==1)
                    q.push(i);
            }

            int left = n; 
            while(!q.empty()){
                int qz=q.size();
                left -= qz;
                if(left==0){
                    while(!q.empty()){
                        ans.push_back(q.front());
                        q.pop();
                    }
                }
                else{
                    for(int i=0;i<qz;i++){
                        int leaf = q.front();
                        q.pop();
                        for(int j=0;j<arr[leaf].size();j++){
                            if(--deg[arr[leaf][j]]==1){
                                q.push(arr[leaf][j]);
                            }
                        }
                    }
                } 
            }
        }
        return ans;

    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();