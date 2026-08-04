class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            for (int val = nums[i] + 1; val < nums[i + 1]; ++val) {
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};