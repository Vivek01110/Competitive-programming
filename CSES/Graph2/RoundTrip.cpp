#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int starting_point = -1;
int ending_point = -1;
bool dfs(int i, vector<bool>&visited, vector<int>&parent, vector<vector<int >>&adj){
    
    visited[i] = true;

    for(int nbr : adj[i]){
        if(!visited[nbr]){
            parent[nbr] = i;
            if(dfs(nbr, visited,parent , adj)){
                return true;
            } 
        }
        else if(nbr != parent[i]){
            starting_point = nbr;
            ending_point = i;
            return true;
        }
    }
    return false;
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

    
    vector<bool>visited(n + 1 , false);
    vector<int> parent(n + 1, -1);


    
     
    for(int i = 1; i <= n; i++){
        if(!visited[i] && dfs(i, visited , parent, adj)){
            break;
        }
    }

    if(starting_point == -1){
        cout << "IMPOSSIBLE";
    }
    else{
        vector<int> cycle;
        
        cycle.push_back(starting_point);
        for(int v = ending_point; v != starting_point ; v= parent[v]){
            cycle.push_back(v);
        }

        cycle.push_back(starting_point); // no need to reverse cuz its a cycle

       
        cout << cycle.size() << endl;
        for(int elm : cycle){
            cout << elm << ' ';
        }
    }
}