#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void bfs(int src , vector<bool>&visited,vector<vector<int>>&adj){
    visited[src] = true;

    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int elm = q.front();
        q.pop();

        for(int nbr : adj[elm]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>>adj(n + 1);

    for(int i= 0; i < m; i++){
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    vector<bool>visited(n + 1 , false);
    vector<int>comp; // one elm from each disconnected components
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bfs(i, visited,adj);
            comp.push_back(i);
        }
    }

    cout << (comp.size() - 1) << endl;
    int maincity = 0;
    if(comp.size() > 1){
        maincity = comp[0];
    }

    for(int i = 1; i < comp.size(); i++){
            cout << maincity << ' ' << comp[i] << endl;
    }
}
