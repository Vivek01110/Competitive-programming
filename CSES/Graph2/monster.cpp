#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<vector<int>>dir = {{0,1}, {1, 0},{0,-1},{-1, 0}};
string p = "RDLU";

void bfs(int n, int m , vector<string>&grid){
    
    queue<vector<int>>q; // {i , j} // time will accesed using monster[i][j]
    vector<vector<int>> monster(n ,vector<int>(m , INT_MAX));
    vector<vector<bool>> visited(n , vector<bool>(m, false));
    pair<int, int> start;
    for(int i= 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'M'){
                q.push({i , j , 0});
                visited[i][j] = true;
                monster[i][j] = 0;     
            }

            if(grid[i][j] == 'A'){
                start = {i , j};
            }
        }
    }

    if(start.first == 0 || start.second == 0 ||
        start.first == n-1 || start.second == m-1){
        cout << "YES" << endl << 0 << endl << "" << endl;
        return;
    }

    while(!q.empty()){
        int r = q.front()[0];
        int c = q.front()[1];
        int t = q.front()[2];
        q.pop();

        // monster[r][c] = min(t , monster[r][c]);
        // monster[r][c] = t;

        for(int k = 0;  k < 4; k++){
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            
            if(grid[nr][nc] != '#' && monster[nr][nc] > monster[r][c] + 1){
                q.push({nr, nc});
                monster[nr][nc] = monster[r][c] + 1;
            }
        }     
    }

    q.push({start.first , start.second , 0});
    visited.assign(n , vector<bool>(m , false));
    vector<vector<pair<pair<int ,int>, char>>>parent(n , vector<pair<pair<int ,int>, char>>(m));

    visited[start.first][start.second] = true;
    bool flag = false;
    pair<int , int> ans;
    

    while(!q.empty()){
        int r = q.front()[0];
        int c = q.front()[1];
        int t = q.front()[2];
        q.pop();

        if(r == 0 || c == 0 || r == n - 1 || c == m - 1){
            flag = true;
            ans = {r , c};
            break;
        }
       

        for(int k = 0;  k < 4; k++){
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];
            
            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            
            if(grid[nr][nc] != '#' && !visited[nr][nc] && monster[nr][nc] > t + 1){
                q.push({nr, nc, t + 1});
                visited[nr][nc] = true;
                parent[nr][nc] = {{r , c},p[k]};
            }
        }     
    }

    if(!flag){
        cout << "NO" << endl;
    }
    else{
 
         
        string path = "";

        while(ans != start){
            int i = ans.first;
            int j = ans.second;

            path += parent[i][j].second;
            ans = parent[i][j].first;     
        }

        reverse(path.begin(), path.end());

        cout << "YES" << endl;
        cout << path.length() << endl;
        
        cout << path << endl;
    }   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m;
    cin >> n >> m;

    vector<string>grid(n);

    for(int i= 0; i < n; i++) cin >> grid[i];

    bfs(n , m , grid);
}