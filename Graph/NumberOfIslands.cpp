#include<queue>
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&visited){
        int m=grid.size();
        int n=grid[0].size();
        visited[i][j]=true;
        vector<vector<int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        for(int k=0;k<4;k++){
            int nx=i+dir[k][0];
            int ny=j+dir[k][1];
            if(nx>=0 && nx<m && ny>=0 && ny<n && visited[nx][ny]==false && grid[nx][ny]=='1'){
               visited[nx][ny]=true;
               dfs(nx,ny,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int c=0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]!=true && grid[i][j]=='1'){
                  dfs(i,j,grid,visited);
                  c++;
            }
            }
        }
        return c;
    }
};
