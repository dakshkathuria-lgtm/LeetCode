class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>&vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = true;

        bool ans = true;

        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+ dc[i];

            if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==0 and !vis[nr][nc]){
                bool smallAns = dfs(nr, nc, grid, vis);
                if(smallAns==false) ans = false;
            }

        }
        if(r==0 or r==n-1 or c==0 or c==m-1) ans=false;
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 and !vis[i][j]){
                    bool smallAns = dfs(i, j, grid, vis);
                    if(smallAns==true) count++;
                }
            }
        }
        return count;
    }
};