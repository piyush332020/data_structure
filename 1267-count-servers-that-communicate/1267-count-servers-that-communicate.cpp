class Solution {
private:
    void solve(int i, int j, vector<vector<int>>& grid,
               vector<vector<int>>& visited, int& count) {

        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = 1;
        count++;

        // Check same row
        for(int k = 0; k < n; k++) {
            if(grid[i][k] == 1 && !visited[i][k]) {
                solve(i, k, grid, visited, count);
            }
        }

        // Check same column
        for(int k = 0; k < m; k++) {
            if(grid[k][j] == 1 && !visited[k][j]) {
                solve(k, j, grid, visited, count);
            }
        }
    }

public:
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && !visited[i][j]) {

                    int count = 0;

                    solve(i, j, grid, visited, count);

                    if(count > 1) {
                        ans += count;
                    }
                }
            }
        }
        return ans;
    }
};