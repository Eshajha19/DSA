class Solution {
public:
    void bfs(vector<vector<int>>&adj,vector<bool>&visited,int source){
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:adj[front]){
                if(!visited[i]){
                  q.push(i);
                  visited[i]=true;
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }   
        bfs(adj,visited,source);  
        if(visited[destination]==true)
          return true;
        return false;
    }
};
