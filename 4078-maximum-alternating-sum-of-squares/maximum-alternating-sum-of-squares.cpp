class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        vector<long long>temp(n);
        for(int i=0;i<n;i++){
            if(nums[i] < 0) 
                nums[i] = nums[i] * -1;
        }
        sort(nums.begin() , nums.end(), greater<int>());
        int j = 0;
        for(int i=0;i<n;i++){
            long long a = 1LL * nums[i]*nums[i];
            if(j<n){
                temp[j] = a;
                j+=2;
            } else{
                j=1;
                temp[j] = a;
                j+=2;
            }
        }

        long long sum = 0;
        for(int i=0;i<n;i++){
            if(i%2==0)
                sum+=temp[i];
            else sum-=temp[i];
        }
        return sum;
    }
};