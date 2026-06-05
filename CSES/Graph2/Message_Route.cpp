#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void bfs(vector<vector<int >>&adj){
    int n = adj.size() - 1;
    
    vector<int>parent(n + 1, -1);
    vector<bool>visited(n + 1 , false);
    queue<int>q;

    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int elm = q.front();
        q.pop();

        if(elm == n)
            break;
        

        for(int nbr : adj[elm]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
                parent[nbr] = elm;
            }
        }
    }

    if(!visited[n]){
        cout << "IMPOSSIBLE";
        return;
    }
    
    vector<int> path;

    int i = n;
    while(i != -1){
        path.push_back(i);
        i = parent[i];
    }

    
    int len = path.size();

    cout << len << endl;

    for(int i = len - 1; i >= 0; i--){
        cout << path[i] << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;


    vector<vector<int >>adj(n + 1);

    for(int i= 0; i < m; i++){
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(adj); 
}