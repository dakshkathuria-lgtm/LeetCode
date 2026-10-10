class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(int i=0;i<pre.size();i++){
            int a = pre[i][0];
            int b = pre[i][1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        if(ans.size()==n) return ans;
        else return {};
    }
};