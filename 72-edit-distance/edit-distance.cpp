class Solution {
public:
    int dp[501][501]{};
    int f(string &s, string &t, int x, int y){
        if(x==0){
            return y;
        }
        if(y==0){
            return x;
        }

        if(dp[x][y]!=-1){
            return dp[x][y];
        }

        if(s[x-1]==t[y-1]){
            return dp[x][y] = f(s, t, x-1, y-1);
        }
        int op1 = f(s, t, x, y-1); // insert
        int op2 = f(s, t, x-1, y); // delete
        int op3 = f(s, t, x-1, y-1); // replace

        return dp[x][y] = 1 + min({op1, op2, op3});

    }
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        memset(dp, -1, sizeof(dp));
        return f(s, t, n , m);
    }
};