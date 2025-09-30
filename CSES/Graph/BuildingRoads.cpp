#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void dfs(int src ,    vector<bool> &visited, vector<vector<int>> &adj ){
    visited[src] = true;

    for(int nb : adj[src]){
        if(!visited[nb]){
            dfs(nb , visited , adj);
        }
    }  
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m;
    cin >> n >> m;

    // vector<pair<int , int>> roads(m);
    vector<vector<int>> adj(n + 1);
    

    for(int i = 0; i < m; i++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> city; // disconnected city any
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            city.push_back(i);
            dfs(i , visited , adj);
        }
    }

    cout << cnt - 1 << endl;

    for(int i = 1; i < city.size(); i++){
        cout << city[0] <<" " << city[i] << endl;
    }



    

    
}