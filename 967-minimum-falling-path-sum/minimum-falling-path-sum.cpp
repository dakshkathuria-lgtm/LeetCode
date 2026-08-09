class Solution {
public:

    int dp[101][101];

    int f(vector<vector<int>>& matrix, int row, int col, int n){
        if(row==n){
            return 0;
        }

        if(dp[row][col]!=1e8){
            return dp[row][col];
        }

        int op1 = 1e8, op2 = 1e8, op3 = 1e8;

        op1 = matrix[row][col] + f(matrix, row+1, col, n);

        if(col>0 and col<n){
            op2 = matrix[row][col] + f(matrix, row+1, col-1, n);
        }
        if(col>=0 and col<n-1){
            op3 = matrix[row][col] + f(matrix, row+1, col+1, n);
        }

        int ans = min({op1, op2, op3});
        return dp[row][col] = ans;

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e8;  
        for(int i= 0;i<n;i++){
            for(int j = 0;j<n;j++){
                dp[i][j] = 1e8;
            }
        }  

        for(int i =0;i<n;i++){
            mini = min(mini, f(matrix, 0, i, n));
        }
        return mini;
    }
};