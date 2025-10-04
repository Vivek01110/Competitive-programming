#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int  ending_point = -1;
int starting_point = -1;
bool dfs(int src,vector<bool> &visited, vector<int>& parent , vector<vector<int>> &adj){
    
    visited[src] = true;
   
    for(int nb : adj[src]){
        if(!visited[nb]){
            parent[nb] = src; 
            if(dfs(nb , visited , parent , adj)){
                return true;
            }          
        }
        else if(nb != parent[src]){
            ending_point = src;
            starting_point = nb;
            return true;   
            
        }
    }

    return false;
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
    vector<bool>visited(n + 1 , 0);
    vector<int> parent(n + 1, -1);
    for(int i = 1; i <= n; i++){
        if(!visited[i] && dfs(i , visited , parent , adj )){
            break;
        }
    }

    

    if(starting_point == -1){
        cout << "IMPOSSIBLE"; // there is no cycle
    }
    else{
        vector<int> cycle;

       cycle.push_back(starting_point);
        for (int v = ending_point; v != starting_point; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(starting_point);

        cout << cycle.size() << endl;
        for(int i = 0; i < cycle.size(); i++){
            cout << cycle[i] << " ";
        }
    }
    
    // first detect cycle 
    // again start f)rom that node and start traversiing whole cycle
    
}