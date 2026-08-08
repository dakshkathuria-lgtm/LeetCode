class Solution {
public:

    int dp[101]{};

    int f(vector<int>& nums, int n , int x){
        
        if(x>=n){
            return 0;
        }

        if(dp[x]!=-1){
            return dp[x];
        }

        int op1 = nums[x] + f(nums, n , x+2);
        int op2 = f(nums, n , x+1);

        return (dp[x] = max(op1, op2));

    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return f (nums, n , 0);
    }
};