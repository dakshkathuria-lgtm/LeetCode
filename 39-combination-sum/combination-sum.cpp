class Solution {
public:

    void f(int index, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& current, int target){
        int n = candidates.size();

        if(target<0){
            return;
        }

        if(target==0){
            ans.push_back(current);
            return;
        }

        if(index == n){
            return;
        }

        int newtarget = target - candidates[index];
        current.push_back(candidates[index]);
        f(index, candidates, ans, current, newtarget);

        current.pop_back();

        f(index+1, candidates, ans, current, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        f(0 , candidates, ans , current, target);
        return ans;
    }
};