#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
// void bfs(int n ,vector<vector<int>> &adj){
    
//     vector<bool> visited(n + 1, false);
    
//     queue<pair<int , pair<int , vector<int>>>> q;
//     q.push({1 , {0 , {1}}});
    

//     bool flag = false;
//     vector<int> ans;
    
//     while(!q.empty()){
//         int curr = q.front().first;
//         int dist = q.front().second.first;
//         vector<int> prev = q.front().second.second;

//         q.pop();


//         for(int nb : adj[curr]){
//             if(!visited[nb]){
//                 visited[nb] = true;
//                 prev.push_back(nb);
//                 q.push({nb , {dist + 1 , prev}});
              

//                 if(nb == n) {
//                     ans = prev;
//                     flag = true;
//                     break;
//                 }
//                   prev.pop_back();
//             }


//         }
//     }

//     if(flag){
//         cout << ans.size() << endl;

//         for(int i =0; i < ans.size(); i++){
//             cout << ans[i] << " ";
//         }

//     }
//     else{
//         cout << "IMPOSSIBLE" << endl;
//     }

    





// }

void bfs(int n ,vector<vector<int>> &adj){
    
    vector<bool> visited(n + 1, false);
    
    queue<int> q;
    vector<int> parent(n+1);
    parent[1] = -1;
    q.push(1);
    visited[1] = true;
    

    bool flag = false;
   
    while(!q.empty()){
        int curr = q.front();
        q.pop();


        for(int nb : adj[curr]){
            if(!visited[nb]){
                visited[nb] = true;
                parent[nb] = curr;   
                q.push(nb);
            
                if(nb == n) {
                    flag = true;
                    break;
                }
                 
            }


        }
    }

    if(flag){
        vector<int> ans;

        ans.push_back(n);
        for(int v = n; parent[v] != -1; v = parent[v]){
            ans.push_back(parent[v]);
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(int i =0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }

    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    





}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(n, adj);
    
}