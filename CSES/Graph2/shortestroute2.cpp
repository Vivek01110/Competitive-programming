#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pii pair<ll , int>
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>>dist(n + 1,vector<ll>(n + 1 , LLONG_MAX));

    for(int i= 1; i <= n; i++){
        dist[i][i] = 0;
    }

    for(int i= 0; i < m; i++){
        int a , b , c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b] , (ll)c);
        dist[b][a] = min(dist[b][a], (ll)c); 
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX){
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
       

        if(dist[a][b] != LLONG_MAX){
            cout << dist[a][b] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// #define pii pair<ll , int>
// void dijkstra(int src,vector<ll>&dist,vector<vector<pair<ll , int>>>&adj){
//     int n = adj.size() - 1;

//     priority_queue<pii , vector<pii>, greater<pii>>pq;

//     dist[src] = 0;
//     pq.push({0, src});

//     while(!pq.empty()){
//         ll currd  = pq.top().first;
//         int elm = pq.top().second;
//         pq.pop();

//         if(currd > dist[elm]) continue;

//         for(auto nb : adj[elm]){
//             int nbr = nb.second;
//             ll w = nb.first;

//             if(currd + w < dist[nbr]){
//                 dist[nbr] = currd + w;
//                 pq.push({dist[nbr], nbr});
//             }
//         }
//     }

// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m, q;
//     cin >> n >> m >> q;

//     vector<vector<pair<ll , int>>>adj(n + 1);

//     for(int i= 0; i  < m; i++){
//         int a , b , c;
//         cin >> a >> b >> c;

//         adj[a].push_back({c, b});
//         adj[b].push_back({c, a});
//     }
//     vector<ll>dist(n + 1 , LLONG_MAX);
//     for(int i = 0; i < q; i++){
//         int a, b;
//         cin >> a >> b;
//         dist.assign(n + 1 , LLONG_MAX);
//         dijkstra(a,dist , adj);

//         if(dist[b] != LLONG_MAX){
//             cout << dist[b] << endl;
//         }
//         else{
//             cout << -1 << endl;
//         }
//     }

// }