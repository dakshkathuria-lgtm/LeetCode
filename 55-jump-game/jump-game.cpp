class Solution {
public:

    int dp[10001]{};

    bool F(vector<int>& nums, int x, int n){
        if (x>=n-1){
            return true;
        }

        if(dp[x]!=-1){
            return dp[x];
        }

        for(int i = 1;i<=nums[x];i++){
            if(F(nums, x+i, n)){
                return dp[x] = true;
            }
        }
        return dp[x] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = F(nums, 0, n);
        return ans;
    }
};