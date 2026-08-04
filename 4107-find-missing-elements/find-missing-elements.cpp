class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> s;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto x: nums){
            s.insert(x);
            mini = min(mini, x);
            maxi = max(maxi ,x);
        }

        vector<int> ans;
        for(int i =mini;i<=maxi;i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            }
        }
        return ans;

    }
};