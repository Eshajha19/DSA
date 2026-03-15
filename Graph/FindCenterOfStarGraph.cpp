class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int maxNode = 0;
        for(auto &e : edges){
            maxNode = max(maxNode, max(e[0], e[1]));
        }
        vector<vector<int>>adj(maxNode+1);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }  
        int m=INT_MIN;
        int x=-1;
        for(int i=0;i<maxNode+1;i++){
            int a=adj[i].size();
            if(a>m){
                m=a;
                x=i;
            }   
        }
        return x;
    }
};
