class Solution {
public:
    int dp[38]{};
    int f(int n){
        if(n==0){
            return 0;
        }
        if(n==1 or n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int op1 = f(n-1);
        int op2 = f(n-2);
        int op3 = f(n-3);

        return dp[n] = op1 + op2 + op3;
    }
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
};