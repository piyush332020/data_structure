class Solution {
private:
    long long int dfs(int i,int j,vector<vector<int>>& grid,int k){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]==0){
            return 0;
        }
        long long int sum = grid[i][j];
        grid[i][j] = 0;
        sum+=dfs(i,j+1,grid,k);
        sum+=dfs(i,j-1,grid,k);
        sum+=dfs(i+1,j,grid,k);
        sum+=dfs(i-1,j,grid,k);
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
        
                if(grid[i][j]!=0){
                    long long int sum=dfs(i,j,grid,k);
                    if(sum%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};