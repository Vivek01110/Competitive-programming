#include<bits/stdc++.h> 
using namespace std;

// Time Limit Exceed

// void bfs(pair<int , int> &src, vector<vector<char>> &grid){
//     int m = grid.size();
//     int n = grid[0].size();

//     vector<pair<pair<int, int>, char>> dir = {{{-1 , 0},'U'},{{1 , 0},'D'},{{0 , -1},'L'},{{0 , 1},'R'}};

//     vector<vector<bool>>visited(m , vector<bool>(n , false));
//     queue<pair<pair<int , int>, pair<int ,string>>>q; //{{{r ,c} , {dist , diststr}}};

//     q.push({src , {0,""}});
//     visited[src.first][src.second] = true;
//     bool flag = false;
//     string path = "";
//     int ansdist = 0;

//     while(!q.empty()){
//         int r = q.front().first.first;
//         int c = q.front().first.second;
       
//         int prevdist = q.front().second.first;
//         string prev = q.front().second.second;

//         q.pop();

//         visited[r][c] = true;

//         if(grid[r][c] == 'B'){
//            flag = true;
//            ansdist = prevdist;
//            path = prev;
//            break;
//         }

//         for(int i = 0; i < 4; i++){
//             int newr = r + dir[i].first.first;
//             int newc = c + dir[i].first.second;
//             string currstr = (prev + dir[i].second);
//             int currdist = prevdist+1;

//             if(newr < m && newr >= 0 && newc < n && newc >= 0 && grid[newr][newc] != '#' && !visited[newr][newc]){
//                 q.push({{newr , newc}, {currdist, currstr}});   
//             }
//         }
//     }

//     if(flag){
//         cout << "YES" << endl;
//         cout << ansdist << endl;

//         cout << path;
//     }
//     else{
//         cout << "NO";
//     }



// }

void bfs(pair<int , int> &src, pair <int, int> &dest ,vector<vector<char>> &grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<char> DIR = {'U' , 'R', 'D' , 'L'};
    vector<int> rowdir = {-1 , 0 , 1 , 0};
    vector<int> coldir = {0 , 1 , 0 , -1};

    vector<vector<bool>>visited(m , vector<bool>(n , false));
    vector<vector<char>>prevmatrix(m , vector<char>(n));
    queue<pair<int ,int>>q; //{r ,c};

    q.push(src);
    visited[src.first][src.second] = true;
    bool flag = false;

    while(!q.empty() && flag == false){
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int newr = r + rowdir[i];
            int newc = c + coldir[i];
           

            if(newr < m && newr >= 0 && newc < n && newc >= 0 && grid[newr][newc] != '#' && !visited[newr][newc]){
                q.push({newr , newc});
                prevmatrix[newr][newc] = DIR[i];   
                 visited[newr][newc] = true;

                 if(grid[newr][newc] == 'B'){
                    flag = true;
                    break;
                 }
            }
        }
    }

    if(flag){
        cout << "YES" << endl;
        int i = dest.first;
        int j = dest.second;
        string path;
        int dist = 0;
        while(i != src.first || j != src.second){
            path += prevmatrix[i][j];
            if(prevmatrix[i][j] == 'U'){
                i++;      
            }
            else if(prevmatrix[i][j] == 'R'){
                j--;
            }
            else if(prevmatrix[i][j] == 'D'){
                i--;
            }
            else{
                j++;
            }

            dist++;
            
        }

        cout << dist << endl;
        reverse(path.begin(), path.end());
        cout << path;
    }
    else{
        cout << "NO";
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

   
    pair<int, int> src; 
    pair<int, int> dest; 
  

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
               src = {i , j}; 
            }
            else if(grid[i][j] == 'B'){
                dest = {i , j};
            }
        
        }
    }

    bfs(src ,dest , grid);

}