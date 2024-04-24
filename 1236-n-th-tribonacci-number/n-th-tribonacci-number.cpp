class Solution {
public:
    int tribonacci(int n) {
        
        if(n==0)
            return 0;
        else if(n==1||n==2)
            return 1;
        else{
            vector<int> adj(n+1);
            adj[0]=0,adj[1]=1,adj[2]=1;
            for(int i=3;i<=n;i++){
                adj[i]=adj[i-1]+adj[i-2]+adj[i-3];
            }
            return adj[n];
        }
        
    }
};