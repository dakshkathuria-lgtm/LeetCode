class Solution {
public:
    int dp[1001][1001]{};
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());

        // find lcs between t and s'
        int n = s.length();
        int m = t.length();

        dp[0][0] = 0;
        for(int i =0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else{
                    int op1 = dp[i][j-1];
                    int op2 = dp[i-1][j];

                    dp[i][j] = max(op1, op2);
                }
            }
        }
        return dp[n][m];
    }
};