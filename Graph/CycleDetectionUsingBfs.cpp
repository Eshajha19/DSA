class Solution {
  public:
    bool bfs(vector<vector<int>>&adj,vector<bool>&visited,vector<int>&parent,int start){
        queue<int>q;
        q.push(start);
        parent[start]=-1;
        visited[start]=true;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            visited[p]=true;
            for(int i=0;i<adj[p].size();i++){
                if(visited[adj[p][i]]==false){
                    visited[adj[p][i]]=true;
                    q.push(adj[p][i]);
                    parent[adj[p][i]]=p;
                }
                else{
                    if(adj[p][i]==parent[p])
                      continue;
                    else
                      return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<bool>visited(V,false);
        vector<int>parent(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(bfs(adj,visited,parent,i))
                  return true;
            }
        }
        return false;
    }
};
