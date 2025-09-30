#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

bool isBipartite(int src ,vector<int>&color , vector<vector<int>>&adj){
    int n = adj.size();
    queue<int> q;

    q.push(src);
    color[src] = 1;  // i am coloring with 1 or 2 // uncololred with -1

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int nb : adj[curr]){
            if(color[nb] == -1){
                q.push(nb);
                color[nb] = (color[curr]%2) + 1; // if 1 -> 2 or 2 -> 1
            }
            else if(color[nb] == color[curr]){ // same color
                return false;
            }
        }

       
    }

     return true;
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

    vector<int> color(n + 1, -1);
    bool isallbipartite = true;
    // for each disconnected components;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
           isallbipartite = isallbipartite &&  isBipartite(i , color , adj);
           if(isallbipartite == false) break;
        }
    }

    if(isallbipartite){
        for(int i = 1; i <= n; i++){
            cout << color[i] << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
   




}