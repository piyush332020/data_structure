class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>ans;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int value=grid[i][j];
                ans.push_back(value);
            }
        }
        int size=ans.size();
        while(k!=0){
            int val=ans[size-1];
            ans.pop_back();
            ans.insert(ans.begin(),val);   
            k--;      
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = ans[i * n + j];
            }
        }
        return grid;
    }
};