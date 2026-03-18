class Solution {
public:
    bool bfs(vector<vector<char>> &grid,vector<vector<bool>>&visited,vector<vector<pair<int,int>>>&parent,int i,int j,int s){
        queue<pair<int,int>>q;
        parent[i][j]={-1,-1};
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size()){
                    continue;
                }
                if(grid[nx][ny]!=s) 
                  continue;
                if(visited[nx][ny]==false){
                visited[nx][ny]=true;
                q.push({nx,ny});
                parent[nx][ny]={x,y};
                }
                else if(parent[x][y]!=make_pair(nx,ny)){
                    return true;
                }
            }
        }
            return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<pair<int,int>>>parent(grid.size(),vector<pair<int,int>>(grid[0].size(),{-1,-1}));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==false){
                    int s=grid[i][j];
                    if(bfs(grid,visited,parent,i,j,s))
                      return true;
                }
            }
        }
        return false;
    }
};
