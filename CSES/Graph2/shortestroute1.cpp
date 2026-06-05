#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pii pair<ll, int>
void drikshtra(vector<vector<pair<int , ll>>>&adj){
    int n = adj.size() - 1;
 
    vector<ll>dist(n + 1 , LONG_LONG_MAX);
 
    priority_queue<pii , vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
     
    dist[1] = 0;
 
    while(!pq.empty()){
        auto [currd , elm]  = pq.top();
        pq.pop();

        if(currd > dist[elm]) continue; // add this line because if currdist is greter than dist we already have , so no need to push neighbour beacuse we will get greter distanc always
 
        for(auto nb : adj[elm]){
            int nbr = nb.first;
            ll w = nb.second;
            if(dist[nbr] > currd + w){
                dist[nbr] = currd + w;
                pq.push({dist[nbr],nbr});
            }
        }
    }
 
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n , m;
    cin >> n >> m;
 
    vector<vector<pair<int, ll>>> adj(n + 1);
 
    for(int i = 0; i < m; i++){
        int a , b , c;
        cin >> a >> b >> c;
 
        adj[a].push_back({b, c});
 
    }
 
    drikshtra(adj);
 
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// void drikshtra(vector<vector<pair<int , ll>>>&adj){
//     int n = adj.size() - 1;
    

//     vector<ll>dist(n + 1 , LONG_LONG_MAX);
 
//     queue<int> q;
//     q.push(1);
     
//     dist[1] = 0;

//     while(!q.empty()){
//         int elm = q.front();
//         q.pop();

//         for(auto nb : adj[elm]){
//             int nbr = nb.first;
//             ll w = nb.second;
//             if(dist[nbr] > dist[elm] + w){
//                 dist[nbr] = dist[elm] + w;
//                 q.push({nbr});
//             }
//         }
//     }

//     for(int i = 1; i <= n; i++){
//         cout << dist[i] << " ";
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n , m;
//     cin >> n >> m;

//     vector<vector<pair<int, ll>>> adj(n + 1);

//     for(int i = 0; i < m; i++){
//         int a , b , c;
//         cin >> a >> b >> c;

//         adj[a].push_back({b, c});

//     }

//     drikshtra(adj);

// }