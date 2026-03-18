class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
        visited[node]=true;
        recStack[node]=true;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
              if(dfs(adj[node][i],adj,visited,recStack))
                return true;
            }
            else if(recStack[adj[node][i]])
              return true;
        }
        recStack[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Directed graph
        for (auto &e : prerequisites) {
            adj[e[0]].push_back(e[1]);
        }
 
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack))
                    return false;
            }
        }

        return true;
    }
};
