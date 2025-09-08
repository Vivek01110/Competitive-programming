#include<bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, char>> dir = {{{-1 , 0},'U'},{{1 , 0},'D'},{{0 , -1},'L'},{{0 , 1},'R'}};

void dfs(int row ,int col ,vector<vector<char>> &grid,vector<vector<int>>&dist , vector<vector<bool>>&visited){
    int n = grid.size();
    int m = grid[0].size();
    visited[row][col] = true;
    string ans;
    
    for(int i = 0; i < 4; i++){
        int newr = row + dir[i].first.first;
        int newc = col + dir[i].first.second;
        char ch = dir[i].second;

        if(newr >= 0 && newr < n && newc >= 0 && newc < m){
            dfs(newr , newc , grid , dist , visited);
            ans.push_back(ch);
            
        }




    }
    
}
int main(){
    int n , m;
    cin >> n >> m;

    vector<vector<char>> grid(n , vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>>dist(n , vector<int> (m , INT_MAX));
    vector<vector<bool>>visited(n , vector<bool> (m , false));
    pair<int, int> src;
    pair<int, int> dest;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                src.first = i;
                src.second = j;
            }
            else if(grid[i][j] == 'B'){
                dest.first = i;
                dest.second = j;
            }
        

        }
    }
   
    string path;
    dfs(src.first  , src.second , grid , dist , visited);

    
    if(dist[dest.first][dest.second] != INT_MAX){
        cout << "YES" << endl;
        cout << dist[dest.first][dest.second];
        cout << path;
    }
      



}