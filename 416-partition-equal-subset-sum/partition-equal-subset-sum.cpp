class Solution {
public:
    int dp[201][20001]{};

    int sum(vector<int>&nums){
        int n = nums.size();
        int x = 0, sum = 0;
        while(x<n){
            sum+=nums[x];
            x++;
        }
        return sum;
    }

    bool f(vector<int>& nums, int x, int target){
        if(target==0){
            return true;
        }
        if(x<0){
            return false;
        }
        if(dp[x][target]!=-1){
            return dp[x][target];
        }

        bool op1 = false;
        if(nums[x]<=target){
            op1 = f(nums, x-1, target-nums[x]);
        }
        bool op2 = f(nums , x-1, target);
        return dp[x][target] = op1 or op2;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(sum(nums) % 2 != 0){return false;}
        else{
            memset(dp, -1, sizeof(dp));
            return f(nums, n-1, sum(nums) /2 );
        }
        return false;
    }
};