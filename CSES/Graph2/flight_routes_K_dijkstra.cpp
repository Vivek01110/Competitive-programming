#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pii pair<ll , int>
#define vl vector<ll>
void dijkstra(int n , int k , vector<vector<pii>>&adj){
    
   

    priority_queue<pii , vector<pii> , greater<pii>>pq;
    vector<vector<ll>>dist(n + 1);

    
   
    pq.push({0 , 1});
    


    while(!pq.empty()){
        auto [currd , elm] = pq.top();
        pq.pop();

        if(dist[elm].size() >= k) continue;
        dist[elm].push_back(currd);

        for(auto [w, nb] : adj[elm]){
            ll newdist = currd + w;
            pq.push({newdist , nb});
        }
    }

    for(int i = 0; i < k; i++){
        cout << dist[n][i] << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pii>>adj(n + 1);

    for(int i= 0; i < m; i++){
        int a , b , c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    dijkstra(n,k, adj);

   

}