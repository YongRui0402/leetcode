#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int root[200000+5000]={0};
        for(int i=0;i<n;i++){
            root[i]=i;
        }
        for(auto edge:edges){
            int x = find(root, edge[0]);
            int y = find(root, edge[1]);
            if(x!=y){
                root[x]=y;
            }
        }
        return true?find(root, source)==find(root, destination):false;
    }
    int find(int root[], int x){
        if(root[x]!=x){
            root[x]=find(root, root[x]);
        }
        return root[x];
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