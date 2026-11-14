class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = 1e8;
        int s = 0;
        for(;s<n;s++){
            int ans = 0;
            for(int e=s;e<n;e++){
                ans+=nums[e];
                if(e-s+1 >=l and e-s+1<=r and ans>0)
                    mini = min(mini, ans);
                
                if(e-s+1>=r){
                    break;
                }
            }
        }
        if(mini==1e8) return -1;
        return mini;
    }
};