class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i=0;
        int count = 0;
        while(i<n1){
            int j=0;
            while(j<n2){
                if(abs(arr1[i] - arr2[j]) <= d){
                    break;
                } else{
                    j++;
                }
            }
            i++;
            if(j==n2) count++;
        }
        return count;
    }
};