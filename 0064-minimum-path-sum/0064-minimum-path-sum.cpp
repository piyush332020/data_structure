class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n) return INT_MAX;
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = solve(grid, i+1, j,dp);
        int right = solve(grid, i, j+1,dp);
        dp[i][j]=min(down,right);
        if(dp[i][j]==INT_MAX) return INT_MAX;
        return dp[i][j]=grid[i][j]+dp[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,0,0,dp);
    }
};