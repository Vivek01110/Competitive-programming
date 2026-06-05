// GPT Code
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,
         vector<vector<int>>& adj,
         vector<int>& vis,
         vector<int>& pathVis,
         vector<int>& parent,
         int& start,
         int& endd) {

    vis[node] = 1;
    pathVis[node] = 1;

    for(int nbr : adj[node]) {

        if(!vis[nbr]) {

            parent[nbr] = node;

            if(dfs(nbr, adj, vis, pathVis, parent, start, endd))
                return true;
        }
        else if(pathVis[nbr]) {

            start = nbr;
            endd = node;
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int start = -1, endd = -1;

    for(int i = 1; i <= n; i++) {

        if(!vis[i]) {

            if(dfs(i, adj, vis, pathVis, parent, start, endd))
                break;
        }
    }

    if(start == -1) {

        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;

    cycle.push_back(start);

    int curr = endd;

    while(curr != start) {

        cycle.push_back(curr);
        curr = parent[curr];
    }

    cycle.push_back(start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";

    for(int x : cycle)
        cout << x << " ";

    cout << "\n";
}
// my code 
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// int dfs(int i ,int p, vector<int>&parent , vector<bool>&visited,  vector<bool>&dfs_visited , vector<vector<int>>&adj){
    
//     visited[i] = true;
//     dfs_visited[i] = true;
//     parent[i] = p;
    

//     for(int nbr : adj[i]){
//         if(!visited[nbr]){
            

//             int ans = dfs(nbr ,i, parent , visited, dfs_visited, adj);
//             if(ans != -1){
//                 return ans;
//             }
//         }
//         else if(dfs_visited[nbr]){
//             parent[nbr] = i;
//             return nbr;
//         }
//     }
//     dfs_visited[i] = false;
   
//     return -1;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n , m;
//     cin >> n >> m;

//     vector<vector<int>>adj(n + 1);

//     for(int i= 0; i < m; i++){
//         int a , b;
//         cin >> a >> b;

//         adj[a].push_back(b);
//     }

//     vector<bool>visited(n + 1, false);
//     vector<bool>dfs_visited(n + 1 , false);
//     vector<int>parent(n + 1 , -1);
//     int cycle_node = -1;
//     for(int i= 1; i <= n; i++){
//         if(!visited[i]){
//             cycle_node = dfs(i ,-1, parent , visited , dfs_visited , adj);
//             if(cycle_node != -1){
//                 break;
//             }
//         }
//     }

//     if(cycle_node == -1){
//         cout << "IMPOSSIBLE" << endl;
//         return 0;
//     }
    
//     vector<int>ans;
//     ans.push_back(cycle_node);

//     int curr = parent[cycle_node];

//     while(curr != cycle_node){
//         ans.push_back(curr);
//         curr = parent[curr];
//     }

//     ans.push_back(curr);

//     reverse(ans.begin(), ans.end());

//     cout << ans.size() << endl;
//     for(int elm : ans){
//         cout << elm << " ";
//     }

//     cout << endl;
// }