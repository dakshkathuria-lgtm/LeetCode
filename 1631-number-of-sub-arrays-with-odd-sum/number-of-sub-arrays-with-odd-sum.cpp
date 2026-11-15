class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        long long even = 1;
        long long odd = 0, sum =0, ans = 0;
        for(int x: arr){
            sum+=x;
            if(sum%2==0){
                ans+=odd;
                even++;
            } else{
                ans+=even;
                odd++;
            }
        }
        return ans%mod;
    }
};