class Solution {
public:

    int dp[201][201]{};

    int f(int x, int y, int m, int n,vector<vector<int>>& grid){
        if(x==m-1 && y==n-1){
            return grid[x][y];
        }

        if(dp[x][y]!=-1){
            return dp[x][y];
        }

        if(x==m-1){
            //go right 
            return grid[x][y] + f(x, y+1, m, n, grid);
        }

        if(y==n-1){
            //go down 
            return grid[x][y] + f(x+1, y, m, n, grid);
        }

        int op1 = grid[x][y] + f(x+1, y, m, n, grid);
        int op2 = grid[x][y] + f(x, y+1, m, n, grid);

        return (dp[x][y] = min(op1, op2));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return f(0,0, m, n, grid);
    }
};