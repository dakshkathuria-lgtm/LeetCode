class Solution {
public:

    int dp[101][101]{};

    // RECURSION FROM FRONT
    // int f(vector<vector<int>>& obstacleGrid, int row , int col, int m , int n){
    //     if(row==m || col==n){
    //         return 0;
    //     }

    //     if(obstacleGrid[row][col]==1){
    //         return 0;
    //     }

    //     if(row==m-1 and col==n-1){
    //         return 1;
    //     }

    //     if(dp[row][col]!=-1){
    //         return dp[row][col];
    //     }

    //     int op1 = f(obstacleGrid, row+1, col, m, n);

    //     int op2 = f(obstacleGrid, row, col+1, m, n);

    //     int ans = op1+op2;

    //     return dp[row][col] = ans;
    // }

    // RECURSION FROM BACK
    int f1(vector<vector<int>>& obstacleGrid, int row , int col, int m , int n){
        if(row<0 or col < 0){
            return 0;
        }
        if(obstacleGrid[row][col]==1){
            return 0;
        }
        if(row== 0 and col==0){
            return 1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        int op1 = f1(obstacleGrid, row-1, col, m, n);
        int op2 = f1(obstacleGrid, row, col-1, m , n);
        
        return dp[row][col] = op1 + op2;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        // return f(obstacleGrid, 0, 0, m, n);
        return f1(obstacleGrid, m-1, n-1, m, n);
    }
};