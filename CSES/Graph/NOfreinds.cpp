#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

bool dfs(int src ,int parent,vector<bool>&visited , vector<vector<int>>& adj){
    visited[src] = true;
    bool iscycle = false;
    for(int nb : adj[src]){
        if(!visited[nb]){
            iscycle = iscycle || dfs(nb , src , visited , adj);
        }
        else if(parent != nb){
            return true;
        }
    }

    return iscycle;
}

void bfs(int src , vector<bool>&visited ,vector<int> &ans, vector<vector<int>>& adj){

    queue<pair<int, int>>q;
    int num = 0;

    while(!q.empty()){
        int curr = q.front();

        for(int i= 09)

        

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
    bool iscycle = false;
    vector<bool> visited(n + 1 , false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
           iscycle =  iscycle || dfs(i ,-1,  visited , adj);
        }
    }

    if(iscycle){
        cout << "IMPOSSIBLE";
    }
    else{
        
        queue<int> q;
        vector<bool> visited(n +1 , false);
        for(int i = 1; i <= n; i++){
            bfs(i , visited ,adj);
        }
        
    }




}