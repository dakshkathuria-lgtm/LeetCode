class Solution {
public:

    int dp[101][101]{};

    // RECURSION FROM FRONT
    // int f(int x, int y, int m , int n){
    //     if(x== m || y==n){
    //         return 0;
    //     }
    //     if(x==m-1 and y==n-1){
    //         return 1;
    //     }

    //     if(dp[x][y]!=-1){
    //         return dp[x][y];
    //     }

    //     // for going down 
    //     int op1 = f(x+1, y, m, n);

    //     // for going right
    //     int op2 = f(x, y+1, m , n);

    //     int ans = op1 + op2;
    //     return (dp[x][y] = ans);
    // }

    // RECURSION FROM BACK
    int f1(int x, int y, int m , int n){
        if(x<0 or y<0){
            return 0;
        }
        if(x==0 and y == 0 ){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }

        int op1 = f1(x-1, y, m, n);
        int op2 = f1(x, y-1, m, n);

        return dp[x][y] = op1 + op2;
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        // return f(0,0, m, n);

        return f1(m-1, n-1, m, n);
    }
};