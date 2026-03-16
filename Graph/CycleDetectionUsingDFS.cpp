class Solution {
  public:
    bool dfs(vector<vector<int>>&adj,vector<bool>&visited,vector<int>&parent,int start){
        visited[start]=true;
        for(int i=0;i<adj[start].size();i++){
            if(visited[adj[start][i]]==false){
                visited[adj[start][i]]=true;
                parent[adj[start][i]]=start;
                if(dfs(adj,visited,parent,adj[start][i]))
                  return true;
            }
            else{
                if(adj[start][i]==parent[start])
                  continue;
                else
                  return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        vector<bool>visited(V,false);
        vector<int>parent(V);
        parent[0]=-1;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(dfs(adj,visited,parent,i))
                  return true;
            }
        }
        return false;
    }
};
