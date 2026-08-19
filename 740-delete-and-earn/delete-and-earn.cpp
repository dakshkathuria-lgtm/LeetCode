class Solution {
public:
    int dp[20001]{};
    int f(map<int, int>& mp, int x){
        if(x<=0){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int op1 = f(mp , x-1);
        int op2 = (x*mp[x]) + f(mp, x-2);

        return dp[x] = max(op1, op2);
    }

    int deleteAndEarn(vector<int>& nums) {
        map<int, int>mp;
        int maxi = 0;
        for(int x: nums){
            mp[x]++;
            maxi = max(maxi, x);
        }
        memset(dp, -1, sizeof(dp));
        return f(mp, maxi);
    }
};