class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool>visited(V,false);
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
             q.push(i);
        }
        while(!q.empty()){
            int p=q.front();
            q.pop();
            visited[p]=true;
            for(int i=0;i<adj[p].size();i++){
                indegree[adj[p][i]]--;
                if(indegree[adj[p][i]]==0)
                q.push(adj[p][i]);
                }
            }
            
        for(int i=0;i<V;i++){
            if(visited[i]==false){
              return true;
            }
        }
        return false;
    }
};
