class Solution {
public:

    int dp[1001][1001]{};

    int f(string &s, string &t, int x, int y){
        if(x<0 or y<0){
            return 0;
        }

        if(dp[x][y]!=-1){
            return dp[x][y];
        }

        if(s[x]==t[y]){
            return dp[x][y] = 1 + f(s, t, x-1, y-1);
        } else{
            int op1 = f(s, t, x-1, y);
            int op2 = f(s, t, x, y-1);

            return dp[x][y] = max(op1, op2);
        }
    }

    int longestCommonSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        memset(dp, -1, sizeof(dp));
        return f(s, t, n-1 , m-1);
    }
};