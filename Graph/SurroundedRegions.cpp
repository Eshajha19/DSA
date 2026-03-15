class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>&visited){
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int x=front.first;
            int y=front.second;
            vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size() && board[nx][ny]=='O' && visited[nx][ny]==false){
                  visited[nx][ny]=true;
                  q.push({nx,ny});}
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')
               bfs(i,0,board,visited);
            if(board[i][board[0].size()-1]=='O')
            bfs(i,board[0].size()-1,board,visited);
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O')
              bfs(0,j,board,visited);
            if(board[board.size()-1][j]=='O')
              bfs(board.size()-1,j,board,visited);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(visited[i][j]!=true)
                   board[i][j]='X';
            }
        }
    }
};
