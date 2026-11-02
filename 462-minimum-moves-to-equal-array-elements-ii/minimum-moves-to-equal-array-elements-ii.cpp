class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median_ele;
        if(n%2==0) median_ele = n/2 -1;
        else median_ele = n/2;
        int moves = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < nums[median_ele]){
                moves += nums[median_ele] - nums[i];
            } else if(nums[i] > nums[median_ele]){
                moves += nums[i] - nums[median_ele];
            } else{continue;}
        }
        return moves;
    }
};