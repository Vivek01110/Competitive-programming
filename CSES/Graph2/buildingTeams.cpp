#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
bool bfs(int src ,vector<vector<int>>&adj,vector<int>&teams){
     int n = adj.size() - 1;

    queue<int> q; // {node , color}
    q.push(src);
    teams[src] = 1;

    while(!q.empty()){
        int elm = q.front();
        q.pop();

        for(int nbr : adj[elm]){
            if(teams[nbr] == -1){
                q.push(nbr);      
                teams[nbr] = (teams[elm] == 1 ? 2 : 1);
            }
            else if(teams[nbr] == teams[elm]){ // if there is cycle present means same node is colored again if it has to be colored same as elm so it would be a conflict , so ans is IMPOSSIBLE
                return false;
            }
        }
    }
    
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<vector<int>>adj(n + 1);

    for(int i= 0; i < m; i++){
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);  
    }

    
    vector<int>teams(n + 1 , -1);
    
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(teams[i] == -1 && bfs(i ,adj , teams) == false){
            flag = false;
            break;
        }
    }

    if(flag){
        
        for(int i= 1; i<= n; i++){
            cout << teams[i] << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
    

    

    





}