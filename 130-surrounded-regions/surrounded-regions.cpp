class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or j==0 or i==n-1 or j==m-1) and board[i][j] == 'O'){
                    vis[i][j] =1;
                    q.push({i,j});
                } 
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c+ dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and board[nrow][ncol]=='O' and vis[nrow][ncol]==0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' and vis[i][j]==0){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};