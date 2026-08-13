class Solution {
public:

    int prefix[1001];
    int dp[1001][1001][2]{};

    int sum(int i, int j){
        return prefix[j+1] - prefix[i];
    }

    int f(vector<int>& stones, int i, int j, bool AliceTurn){

        if(i==j){
            return 0;
        }

        if(dp[i][j][AliceTurn]!=-1){
            return dp[i][j][AliceTurn];
        }

        if(AliceTurn){
            int left = sum(i+1, j) + f(stones, i+1, j, false);
            int right = sum(i,j-1) + f(stones, i, j-1, false);

            return dp[i][j][AliceTurn] = max(left, right);

        } else{
            int left = -sum(i+1, j) + f(stones, i+1, j, true);
            int right = -sum(i, j-1) + f(stones, i, j-1, true);

            return dp[i][j][AliceTurn] = min(left, right);
        }
    }   

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        prefix[0] = 0;

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        memset(dp, -1, sizeof(dp));
        return f(stones, 0, n-1, true);
    }
};