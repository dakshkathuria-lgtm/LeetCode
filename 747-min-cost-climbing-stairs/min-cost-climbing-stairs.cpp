class Solution {
public:

    int dp[1001]{};

    int F(vector<int>& cost, int x ){

        if(x==0){
            return cost[0];
        }
        if(x==1){
            return cost[1];
        }

        if(dp[x]!=-1){
            return dp[x];
        }

        int op1 = cost[x] + F(cost, x-1);
        int op2 = cost[x] + F(cost, x-2);

        return (dp[x]=min(op1, op2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        int ans1 = F(cost, n-1);
        int ans2 = F(cost, n-2);

        int ans = min(ans1, ans2);
        return ans;
    }
};