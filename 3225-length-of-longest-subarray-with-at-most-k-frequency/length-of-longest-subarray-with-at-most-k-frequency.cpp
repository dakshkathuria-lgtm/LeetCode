class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int len = 0;
        int s = 0, e = 0;
        for(;e<nums.size();e++){
            mp[nums[e]]++;
            
            while(mp[nums[e]] > k) {
                mp[nums[s]]--;
                s++;
            }

            len = max(len, e-s+1);
        }
        return len;
    }
};