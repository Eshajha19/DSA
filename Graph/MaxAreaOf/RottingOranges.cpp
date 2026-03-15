class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        vector<vector<int>>visited(mat.size(),vector<int>(mat[0].size(),-1));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=0;
                }
            }
        }
        int maxi=0;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.first;
            int y=a.second;
            vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx>=0 && nx<mat.size() && ny>=0 && ny<mat[0].size() && visited[nx][ny]==-1 && mat[nx][ny]==1){
                    q.push({nx,ny});
                    visited[nx][ny]=visited[x][y]+1;
                    maxi=max(maxi,visited[nx][ny]);
                }
            }
        }
        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited[0].size();j++){
                if(mat[i][j]==1 && visited[i][j]==-1)
                  return -1;
            }
        }
        return maxi;
    }
};
