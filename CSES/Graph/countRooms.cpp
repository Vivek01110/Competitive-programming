#include<bits/stdc++.h>
using namespace  std;
void bfs(int i  , int j ,vector<vector<char>> &grid , vector<vector<bool>> &visited  ){
    int n = grid.size();
    int m = grid[0].size ();
    queue<pair<int,int>> q;
    q.push({i,j});
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        if(visited[p.first][p.second]) continue;
        visited[p.first][p.second] = true;


        for(int i=0; i < 4; i++){
            int newr = p.first+dr[i];
            int newc = p.second+dc[i];

            if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == '.'){
                q.push({newr , newc});

            }
        }
    }
    
}
int main(){
    int n , m;
    cin >> n >> m;

    vector<vector<char>>grid(n , vector<char> (m));

    for(int i= 0; i< n; i++){
        for(int j =0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited (n , vector<bool> (m , false));
    int cnt = 0;
      for(int i= 0; i< n; i++){
        for(int j =0; j < m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                cnt ++;
                bfs(i , j , grid , visited);
            }
        }

      
    }
      cout << cnt;


}