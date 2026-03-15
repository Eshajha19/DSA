class Solution {
public:
    int bfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int i,int j){
        int c=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=true;
        c++;
        while(!q.empty()){
            auto p=q.front();
            int x=p.first;
            int y=p.second;
            q.pop();
            vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && visited[nx][ny]==false && grid[nx][ny]==1){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                    c++;
                }
            }
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                  int a=bfs(grid,visited,i,j);
                  ans=max(ans,a);
                }
            }
        }
        if(ans<=0)
          return 0;
        return ans;
    }
};
