class Solution {
public: 
    int dp[501][501]{};
    int LCS(string &s, string &t){
        int n = s.length();
        int m = t.length();

        for(int i =0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j =0;j<=m;j++){
            dp[0][j] = 0;
        }

        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else{
                    int op1 = dp[i-1][j];
                    int op2 = dp[i][j-1];

                    dp[i][j] = max(op1, op2);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string s, string t) {
        int length = LCS(s,t);
        return (s.length() + t.length() - 2*length);
    }
};