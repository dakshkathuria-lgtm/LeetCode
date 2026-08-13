class Solution {
public:

    int dp[30001][2]{};

    int f(vector<int>& prices, int curridx, int buy){

        if(curridx == prices.size()){
            return 0;
        }

        if(dp[curridx][buy]!= -1){
            return dp[curridx][buy];
        }

        if(buy==1){
            int op1 = prices[curridx] + f(prices, curridx+1, 0);// sell 
            int op2 = f(prices, curridx+1, 1);// not sell

            return dp[curridx][buy] = max(op1, op2);
        } else{
            int op1 = -prices[curridx] + f(prices, curridx+1, 1);// buy
            int op2 = f(prices, curridx+1, 0);// not buy

            return dp[curridx][buy]= max(op1, op2);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curridx = 0;
        memset(dp, -1, sizeof(dp));
        return f(prices, 0, 0);
    }
};