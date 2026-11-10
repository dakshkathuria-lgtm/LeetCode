class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            int op1 = costs[i] + 1 + dp[i+1];

            int op2 = INT_MAX;
            if(i+2<=n){
                op2 = costs[i+1] + 4 + dp[i+2];
            }

            int op3 = INT_MAX;
            if(i+3<=n){
                op3 = costs[i+2] + 9 + dp[i+3];
            }
            dp[i] = min({op1, op2, op3});
        }
        return dp[0];
    }
};