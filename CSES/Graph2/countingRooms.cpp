#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<vector<int>> dir = {{-1 , 0},{1, 0} , {0, -1}, {0,1}};
void bfs(int row , int col , vector<string> &grid,vector<vector<bool>>&visited){
    int n = grid.size();
    int m = grid[0].size();
    visited[row][col] == true;

    queue<pair<int , int>>q;

    q.push({row, col});

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for(int k = 0; k < 4; k++){
            int newr = r + dir[k][0];
            int newc = c + dir[k][1];

            if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == '.' && !visited[newr][newc]){
                q.push({newr , newc});
                visited[newr][newc] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string>grid(n);

    for(int i= 0; i < n; i++) cin >> grid[i];

    int cnt = 0;

    vector<vector<bool>>visited(n, vector<bool>(m , false));

    for(int i= 0; i< n; i++){
        for(int j= 0;  j < m; j++){
            if(grid[i][j]== '.' && !visited[i][j]){
                cnt++;
                bfs(i, j ,grid , visited);
            }
        }
    }

    cout << cnt;
}