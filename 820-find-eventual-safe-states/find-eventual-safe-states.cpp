class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        for(int i=0;i<n;i++){
            for(auto j : graph[i]){
                adjRev[j].push_back(i);
            }
        }

        vector<int> indegree(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(auto nbr : adjRev[i]){
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {q.push(i);}
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto nbr : adjRev[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) {q.push(nbr);}
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};