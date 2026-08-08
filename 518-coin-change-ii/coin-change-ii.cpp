class Solution {
public:

    int dp[5001][301]{};

    int f(vector<int>& coins, int amount , int n ){
        
        if(amount==0){
            return 1;
        }

        if(amount < 0 || n==0){
            return 0;
        }

        if(dp[amount][n]!=-1){
            return dp[amount][n];
        }

        int op1 = f(coins, amount - coins[n-1], n);
        int op2 = f(coins , amount , n-1);

        return (dp[amount][n] = op1 + op2);

    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return f(coins, amount , coins.size());
    }
};