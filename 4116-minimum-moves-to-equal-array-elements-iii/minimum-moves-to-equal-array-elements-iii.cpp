class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i] > maxi) maxi = nums[i];
        }
        int moves = 0;
        for(int i=0;i<n;i++){
            moves += maxi-nums[i];
        }
        return moves;
    }
};