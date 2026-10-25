class Solution {
private:
    bool dfs(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || i<0 || j>=n || j<0){
            return false;
        }
        if(grid[i][j]==1){
            return true;
        }
        grid[i][j]=1;
        bool left=dfs(i,j-1,grid);
        bool right=dfs(i,j+1,grid);
        bool up=dfs(i-1,j,grid);
        bool down=dfs(i+1,j,grid);
        if(left && right && up && down) return true;
        return false;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};