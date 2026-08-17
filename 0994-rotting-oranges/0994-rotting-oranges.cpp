class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int count=0;
        int fresh=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty() && fresh>0){
            int lev=q.size();

            while(lev>0){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(y-1>=0 && grid[x][y-1]==1){
                    q.push({x,y-1});
                    fresh--;
                    grid[x][y-1]=2;
                }
                if(y+1<n && grid[x][y+1]==1){
                    q.push({x,y+1});
                    fresh--;
                    grid[x][y+1]=2;
                }
                if(x-1>=0 && grid[x-1][y]==1){
                    q.push({x-1,y});
                    fresh--;
                    grid[x-1][y]=2;
                }
                if(x+1<m && grid[x+1][y]==1){
                    q.push({x+1,y});
                    fresh--;
                    grid[x+1][y]=2;
                }
                lev--;
            }
            count++;
        }
        if(fresh==0) return count;
        return -1;
    }

};