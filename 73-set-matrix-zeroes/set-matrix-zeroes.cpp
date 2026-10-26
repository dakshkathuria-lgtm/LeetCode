class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<int, pair<int, int>> mp;
        int k =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    mp[k++]={i,j};
                }
            }
        }

        for(int i=0;i<k;i++){
            int r = mp[i].first;
            int c = mp[i].second;

            for(int j=0;j<m;j++){
                matrix[r][j] = 0;
            }

            for(int i=0;i<n;i++){
                matrix[i][c] = 0;
            }
        }
        return ;
    }
};