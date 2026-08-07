class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        multiset<int> st(nums1.begin(), nums1.end());

        for(int x:nums2){
            if(st.find(x)!=st.end()){
                ans.push_back(x);
                st.erase(st.find(x));
            }
        }
        return ans;
    }
};