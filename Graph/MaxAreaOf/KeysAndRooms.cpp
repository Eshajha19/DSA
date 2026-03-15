class Solution {
public:
    void bfs(int i,vector<vector<int>>& rooms,vector<bool>&visited){
        queue<int>q;
        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            visited[p]=true;
            for(int j=0;j<rooms[p].size();j++){
                if(visited[rooms[p][j]]==false){
                    q.push(rooms[p][j]);
                    visited[rooms[p][j]]=true;
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),false);
        bfs(0,rooms,visited);
        int s=0;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==true)
              s++;
        }
        if(s==rooms.size())
          return true;
        return false;
    }
};
