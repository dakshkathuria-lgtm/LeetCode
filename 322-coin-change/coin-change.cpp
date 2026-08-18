class Solution {
public:

    int dp[10001][13]{};

    // int f(vector<int>& coins, int amount , int n){
    //     if(amount ==0){
    //         return 0;
    //     }

    //     if(amount < 0 || n==0){
    //         return 1e8;
    //     }

    //     if(dp[amount][n]!=-1){
    //         return dp[amount][n];
    //     }

    //     int op1 = 1+ f(coins, amount - coins[n-1], n);
    //     int op2 = f(coins, amount, n-1);

    //     return (dp[amount][n] = min(op1, op2));
    // }

    int coinChange(vector<int>& coins, int amount) {
        // memset(dp, -1, sizeof(dp));
        // int ans=  f(coins, amount, coins.size());
        // return (ans==1e8) ? -1 : ans;

        int n = coins.size();
        // dp[amount][n] : min number of coins needed to make amount using first n coins
        for(int a = 0; a <= amount; a++) {
            for(int j = 0; j <= n; j++) {
                dp[a][j] = 1e8;
            }
        }

        for(int j =0;j<=n;j++){
            dp[0][j] = 0; // amount 0 req 0 coins
        }

        for(int i =1;i<=amount;i++){
            for(int j =1;j<=n;j++){
                dp[i][j] = dp[i][j-1];

                if(coins[j-1]<=i){
                    dp[i][j] = min(dp[i][j], 1 + dp[i-coins[j-1]][j]);
                }
            }
        }
        return dp[amount][n] ==1e8 ? -1 : dp[amount][n];
    }
};