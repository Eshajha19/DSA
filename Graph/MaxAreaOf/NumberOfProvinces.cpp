class Solution {
public:
    void bfs(vector<vector<int>>& connect,vector<int>&visited,int i){
        queue<int>q;
        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            visited[p]=true;
            for(int j=0;j<connect[p].size();j++){
                if(visited[connect[p][j]]==false){
                  q.push(connect[p][j]);
                  visited[connect[p][j]]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>visited(isConnected.size(),false);
        int c=0;
        vector<vector<int>>connect(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1)
                   connect[i].push_back(j);
            }
        }
        for(int i=0;i<isConnected.size();i++){
                if(visited[i]==false){
                    bfs(connect,visited,i);
                    c++;
                }
            }
        return c;
    }
};
