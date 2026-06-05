#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<int> topo_sort(vector<vector<int>>&adj){
    int n = adj.size() -1;
    vector<int> ans;

    vector<int>indegree(n + 1 , 0);

    for(int i = 1; i <= n; i++){
        for(int elm : adj[i]){
            indegree[elm]++;
        }
    }

    queue<int> q;

    for(int i= 1; i <= n; i++){
         if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int elm = q.front();
        q.pop();

        ans.push_back(elm);

        for(int nbr : adj[elm]){
            indegree[nbr]--;

            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }

     

    return ans; // asummng graph is DAG 
}
void topo_DP(vector<vector<int>>&adj){
    int n = adj.size() - 1;
    vector<int>toporder = topo_sort(adj);
    vector<int>dp(n + 1 , -1); // dp[i] =>longest distance from node1 to ith node
    vector<int> parent(n + 1 , -1);
    dp[1] = 0;
    for(int u  : toporder){
        
        for(int v : adj[u]){
            if(dp[u] != -1 && dp[v] < dp[u] + 1){
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if(dp[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> path;
    path.push_back(n);

    int curr = n;

    while(curr != 1){
        curr = parent[curr];
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    
    for(int elm : path){
        cout << elm << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    topo_DP(adj);

}

// TLE, but Correct
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// void bfs(int src , vector<vector<int>>&adj){
//     int n = adj.size() - 1;
//     priority_queue<pair<int , int>>q;
//     vector<int>dist(n + 1, 0);
//     vector<int> parent(n + 1, -1);
//     q.push({0,1});

    
//     // int maxdist = 0;
//     while(!q.empty()){
//         auto [currd , elm] = q.top();
//         q.pop();

//         // if(elm == n){
//         //     maxdist = max(maxdist , dist);
//         // }
//         // maxdist dont need it beacuse longest path will be in parent array
        

//         for(int nbr : adj[elm]){
//             if(dist[nbr] < currd + 1){
//                 dist[nbr] = currd + 1;
//                 q.push({dist[nbr], nbr});
//                 parent[nbr] = elm;
//             }
//         }
//     }

//     if(parent[n] == -1){
//         cout << "IMPOSSIBLE" << endl;
//     }
//     else{
        
//         vector<int>path;
//         path.push_back(n);

//         int curr = n;

//         while(curr != 1){
//             curr = parent[curr];
//             path.push_back(curr);
//         }

//         reverse(path.begin(), path.end());

//         cout << path.size() << endl;
//         for(int elm : path){
//             cout << elm << ' ';
//         }
//     }   
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adj(n + 1);

//     for(int i = 0; i < m; i++){
//         int u , v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//     }

//     bfs(1,adj);

// }



// its wrong because of visited we will never visit n again so we wil not get longer path
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// void bfs(int src , vector<vector<int>>&adj){
//     int n = adj.size() - 1;
//     vector<bool>visited(n + 1 , false);
//     vector<int> parent(n + 1, -1);

//     queue<pair<int , int>>q;
//     // int maxdist = 0;
//     while(!q.empty()){
//         auto [dist , elm] = q.front();
//         q.pop();

//         // if(elm == n){
//         //     maxdist = max(maxdist , dist);
//         // }
//         // maxdist dont need it beacuse longest path will be in parent array

//         for(int nbr : adj[elm]){
//             if(!visited[nbr]){
//                 q.push({dist + 1 , nbr});
//                 visited[nbr] = true; 
//                 parent[nbr] = elm;
//             }
//         }
//     }

//     if(parent[n] == -1){
//         cout << "IMPOSSIBLE" << endl;
//     }
//     else{
        
//         vector<int>path;
//         path.push_back(n);

//         int curr = n;

//         while(curr != -1){
//             curr = parent[curr];
//             path.push_back(curr);
//         }

//         reverse(path.begin(), path.end());

//         cout << path.size() << endl;
//         for(int elm : path){
//             cout << elm << ' ';
//         }

        





//     }

    
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adj(n + 1);

//     for(int i = 0; i < n; i++){
//         int u , v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//     }

//     bfs(1,adj);

// }