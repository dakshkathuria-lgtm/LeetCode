class Solution {
public:

    // int dp[201][201]{};
    int dp1[201][201];
    
    // RECURSION FROM FRONT
    // int f(int x, int y, int m, int n,vector<vector<int>>& grid){
    //     if(x==m-1 && y==n-1){
    //         return grid[x][y];
    //     }

    //     if(dp[x][y]!=-1){
    //         return dp[x][y];
    //     }

    //     if(x==m-1){
    //         //go right 
    //         return (dp[x][y] = grid[x][y] + f(x, y+1, m, n, grid));
    //     }

    //     if(y==n-1){
    //         //go down 
    //         return (dp[x][y] = grid[x][y] + f(x+1, y, m, n, grid));
    //     }

    //     int op1 = grid[x][y] + f(x+1, y, m, n, grid);
    //     int op2 = grid[x][y] + f(x, y+1, m, n, grid);

    //     return (dp[x][y] = min(op1, op2));
    // }

    // RECURSION FROM BACK
    // int f1(int x, int y, int m , int n, vector<vector<int>>& grid){
    //     if(x==0 and y==0){
    //         return grid[x][y];
    //     }
    //     if(x==0){
    //         return dp[x][y] = grid[x][y] + f1(x,y-1, m , n , grid);
    //     }
    //     if(y==0){
    //         return dp[x][y] = grid[x][y] + f1(x-1,y, m , n , grid);
    //     }
    //     if(dp[x][y]!=-1){
    //         return dp[x][y];
    //     }
    //     int op1 = grid[x][y] + f1(x-1, y, m, n, grid);
    //     int op2 = grid[x][y] + f1(x, y-1, m, n, grid);

    //     return dp[x][y] = min(op1, op2);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // memset(dp, -1, sizeof(dp));
        // return f(0,0, m, n, grid);
        // return f1(m-1, n-1, m, n, grid);
        for(int i=0;i<=m;i++){
            for(int j =0;j<=n;j++){
                dp1[i][j] = 1e8;
            }
        }

        for(int i =1;i<=m;i++){
            for(int j =1;j<=n;j++){
                if(i==1 and j==1){dp1[i][j] = grid[i-1][j-1];}
                else{
                    dp1[i][j] = grid[i-1][j-1] + min(dp1[i-1][j] , dp1[i][j-1]);
                }
            }
        }
        return dp1[m][n];
    }
};