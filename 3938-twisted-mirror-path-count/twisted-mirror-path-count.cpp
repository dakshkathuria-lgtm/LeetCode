class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[501][501][2]{};
    int func(int i, int j, vector<vector<int>>& grid, int dir){
        int m = grid.size();
        int n = grid[0].size();

        if(i==m-1 and j==n-1) return dp[i][j][dir] = 1;
        if(i==m or j==n or i<0 or j<0) return 0;

        if(dp[i][j][dir]!=-1) return dp[i][j][dir];

        if(grid[i][j]==1){
            if(dir==0)
                return dp[i][j][dir] = func(i+1, j, grid, 1); // 0 for right and 1 for down
            else
                return dp[i][j][dir] = func(i,j+1, grid, 0);
        }
        int op1 = func(i,j+1, grid, 0);
        int op2 = func(i+1, j, grid, 1);

        return dp[i][j][dir] = (op1+ op2)%MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans1 = func(0,1,grid,0);
        int ans2 = func(1,0,grid,1);
        return (ans1+ ans2)%MOD;
    }
};