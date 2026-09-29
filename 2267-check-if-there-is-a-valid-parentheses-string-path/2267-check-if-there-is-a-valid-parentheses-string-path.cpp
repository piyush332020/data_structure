class Solution {
private:
    bool solve(int i, int j, int balance, vector<vector<char>>& grid, vector<vector<vector<char>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m)
            return false;
        if(grid[i][j] == '(')
            balance++;
        else
            balance--;
        if(balance < 0)
            return false;
            
        if(dp[i][j][balance]!=-1) return dp[i][j][balance];

        if(i == n-1 && j == m-1) {
            if(balance==0) return true;
            else return false;
        }
        bool down = solve(i+1, j, balance, grid ,dp);
        bool right = solve(i, j+1, balance, grid ,dp);
        return dp[i][j][balance]= down || right;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<char>>>dp(n,vector<vector<char>>(m,vector<char>(n+m+1,-1)));
        if((n+m-1)%2!=0){
            return false;
        }
        return solve(0,0,0,grid,dp);
    }
};