class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int i =low, j = mid+1;
        while(i<=mid and j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            } else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[low + k] = temp[k];
        }
    }
    void mergesort(vector<int>& nums, int low, int high){
        if(low<high){
            int mid = low + (high-low)/2;
            mergesort(nums, low, mid);
            mergesort(nums, mid+1, high);

            merge(nums, low, mid, high);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int i = 0, j = nums.size()-1;
        mergesort(nums, i, j);
        return nums[nums.size()-k];
    }
};