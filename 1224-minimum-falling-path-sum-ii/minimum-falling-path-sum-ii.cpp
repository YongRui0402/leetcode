class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid[0].size();
        if(n==1)
            return grid[0][0];
        for(int i=1;i<n;i++){
            int m1=100*250,i1=-1,m2=100*250,i2=-1;
            for(int j=0;j<n;j++){
                if(grid[i-1][j]<m1){
                    m2=m1;
                    i2=i1;
                    m1=grid[i-1][j];
                    i1=j;
                }
                else if(grid[i-1][j]<m2){
                    m2=grid[i-1][j];
                    i2=j;
                }
            }
            // cout<<i1<<" "<<m1<<" "<<i2<<" "<<m2<<" "<<endl;
            for(int j=0;j<n;j++){
                if(j!=i1)
                    grid[i][j]+=m1;
                else
                    grid[i][j]+=m2;
            }
        }
        int ans=100*250;
        for(int j=0;j<n;j++){
            ans=min(grid[n-1][j],ans);
        }
        return ans;
    }
};