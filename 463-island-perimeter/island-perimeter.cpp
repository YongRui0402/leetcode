class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int hsum = 0,hnow=0,vsum=0,vnow=0;
        cout<<n<<" "<<m<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    hnow++;
                }
                else{
                    if(hnow)
                        hsum += 2;
                    hnow = 0;
                }
            }
            if(hnow>0){
                hsum += 2;
                hnow = 0;
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    vnow++;
                }
                else{
                    if(vnow)
                        hsum += 2;
                    vnow = 0;
                }
            }
            // cout << hsum << " " << vsum << endl;
            if(vnow>0){
                vsum += 2;
                vnow = 0;
            }
        }
        
        return  hsum+vsum;
    }
};