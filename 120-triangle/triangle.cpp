class Solution {
public:

    int dp[201][201];

    int f(vector<vector<int>>& triangle, int row, int index, int m){
        if(row==m){
            return 0;
        }

        if(dp[row][index] != 1e8){
            return dp[row][index];
        }

        // if(index==row){
        //     return dp[row][index] = triangle[row][index] + f(triangle, row+1, index, m);
        // }

        int op1 = triangle[row][index] + f(triangle, row+1, index, m);
        int op2 = triangle[row][index] + f(triangle, row+1, index+1, m);

        int ans = min(op1, op2);
        return dp[row][index] = ans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
        int rows = 0;
        int index = 0;
        for(int i =0;i<201;i++){
            for(int j =0;j<201;j++){
                dp[i][j] = 1e8;
            }
        }
        return f(triangle, 0, 0, m);
    }
};