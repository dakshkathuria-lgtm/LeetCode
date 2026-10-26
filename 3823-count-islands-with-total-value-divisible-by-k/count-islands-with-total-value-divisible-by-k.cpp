class Solution {
public: 
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    long long dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int m = grid.size();
        int n = grid[0].size();

        visited[r][c] = true;
        long long sum = grid[r][c];

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 and nr<m and nc>=0 and nc<n and grid[nr][nc]>0 and !visited[nr][nc]){
                sum+=dfs(nr, nc, grid, visited);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 and !visited[i][j]){
                    long long sum = dfs(i, j, grid, visited);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};