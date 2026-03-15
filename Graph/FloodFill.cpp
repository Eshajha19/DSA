class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        visited[sr][sc]=true;
        int b=image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.first;
            int y=a.second;
            vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size() && visited[nx][ny]==false && 
                image[nx][ny]==b){
                    q.push({nx,ny});
                    image[nx][ny]=color;
                    visited[nx][ny]=true;
                }
            }
        }
        return image;
    }
};
