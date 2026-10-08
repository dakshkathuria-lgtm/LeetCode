class Solution {
public:

    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj){
        visited[node]=1;
        for(int nbr : adj[node]){
            if(visited[nbr]==0){
                dfs(nbr, visited, adj);
            }
        }
        return ;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int province = 0;
        vector<bool>visited(n,0);
        for(int i =0;i<n;i++){
            if(visited[i]==0){
                dfs(i, visited, adj);
                province++;
            }
        }
        return province;
    }
};