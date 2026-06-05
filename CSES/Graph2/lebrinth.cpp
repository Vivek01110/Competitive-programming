#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<pair<pair<int , int>, char>> dir = {{{-1 , 0},'U'},{{1, 0},'D'} , {{0, -1},'L'}, {{0,1},'R'}};
bool bfs(int row , int col , vector<string> &grid,vector<vector<bool>>&visited,vector<vector<pair<pair<int , int>, char>>>&parent){
    int n = grid.size();
    int m = grid[0].size();
    visited[row][col] = true;
    
    
    queue<pair<int , int>>q;

    q.push({row, col});

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;

        if(grid[r][c] == 'B')
            return true;

        q.pop();

        for(int k = 0; k < 4; k++){
            int newr = r + dir[k].first.first;
            int newc = c + dir[k].first.second;
            char ch = dir[k].second;

            if(newr >= 0 && newr < n && newc >= 0 && newc < m && (grid[newr][newc] == '.' || grid[newr][newc] == 'B') && !visited[newr][newc]){
                q.push({newr , newc});
                visited[newr][newc] = true;
                parent[newr][newc] = {{r , c}, ch};
            }
        }
    }

    return false;
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
    vector<vector<pair<pair<int , int>, char>>>parent(n , vector<pair<pair<int , int>,char>>(m));
    bool ans = false;
    for(int i= 0; i< n; i++){
        for(int j= 0;  j < m; j++){
            if(grid[i][j]== 'A'){
                ans = bfs(i, j ,grid , visited,parent);
                break;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << endl;

    if(ans){
        int r = 0, c = 0;
        for(int i= 0; i< n; i++){
            for(int j= 0;  j < m; j++){
                if(grid[i][j]== 'B'){
                   r = i;
                   c = j;  
                }
            }
        }
        string ans = "";
        while(grid[r][c] != 'A'){
             int newr = parent[r][c].first.first;
             int newc = parent[r][c].first.second;
             char ch = parent[r][c].second;

             ans += ch;
             r = newr;
             c = newc;
        }

        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        cout << ans;
    
    }
}