class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;

        queue<pair<int,int>>q;
        int m=board.size();
        int n=board[0].size();
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                q.push({i,0});
                board[i][0] = 'S';
            }
            if(board[i][n-1] == 'O') {
                q.push({i,n-1});
                board[i][n-1] = 'S';
            }
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') {
                q.push({0,j});
                board[0][j] = 'S';
            }
            if(board[m-1][j] == 'O') {
                q.push({m-1,j});
                board[m-1][j] = 'S';
            }
        }
        while(!q.empty()){
            int level=q.size();
            while(level>0){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(y-1>=0 && board[x][y-1]=='O'){
                    q.push({x,y-1});
                    board[x][y-1]='S';
                }
                if(y+1<n && board[x][y+1]=='O'){
                    q.push({x,y+1});
                    board[x][y+1]='S';
                }
                if(x-1>=0 && board[x-1][y]=='O'){
                    q.push({x-1,y});
                    board[x-1][y]='S';
                }
                if(x+1<m && board[x+1][y]=='O'){
                    q.push({x+1,y});
                    board[x+1][y]='S';
                }    
                level--;         
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){ board[i][j]='X';}
                else if(board[i][j]=='S'){ board[i][j]='O';}
            }
        }         
    }
};