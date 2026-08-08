class Solution {
public:

    int dp[10001][13]{};

    int f(vector<int>& coins, int amount , int n){
        if(amount ==0){
            return 0;
        }

        if(amount < 0 || n==0){
            return 1e8;
        }

        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }

        int op1 = 1+ f(coins, amount - coins[n-1], n);
        int op2 = f(coins, amount, n-1);

        return (dp[amount][n] = min(op1, op2));
    }


    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans=  f(coins, amount, coins.size());
        return (ans==1e8) ? -1 : ans;
    }
};