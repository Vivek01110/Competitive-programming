#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<int> topo_sort(vector<vector<int>>&adj){
    int n = adj.size() - 1;

    vector<int>indegree(n + 1 , 0);

    for(int i = 1; i <= n; i++){
        for(int v : adj[i]){
            indegree[v]++;
        }
    }

    queue<int> q;

    for(int i= 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    vector<int>ans;
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

    return ans;
}

void topo_DP_Count(vector<vector<int>>&adj){
    int n = adj.size() - 1;
    vector<int> top_order = topo_sort(adj);
    vector<ll> dp(n + 1 , -1);
    
    dp[1] = 1;
    for(int u : top_order){
        for(int v : adj[u]){
            if(dp[u] == -1) continue;

            if(dp[v] == -1){
                dp[v] = dp[u];
            }
            else{
                dp[v] += dp[u]%MOD;
                dp[v] %= MOD;
            }
        }
    }

    if(dp[n] == -1){
        cout << 0 << endl;
    }
    else{
        cout << dp[n] << endl;
    }

    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ,m;
    cin >> n >> m;

    vector<vector<int>>adj(n + 1);

    for(int i =0; i < m; i++){
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    topo_DP_Count(adj);

}