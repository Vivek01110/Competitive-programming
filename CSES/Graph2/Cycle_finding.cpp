#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<int , int, ll>>edges;
    

    for(int i= 0; i < m; i++){
        int a,b ,c;
        cin >> a >> b >> c;

        edges.push_back({a,b,c}); // {u,v,w}
        
    }

    // bellaman ford;
    vector<ll>dist(n + 1,0); // let suppose all nodes are source
    vector<int> relaxant(n + 1 , -1);
    int cycle_node = -1;
    for(int i = 0; i < n; i++){
        cycle_node = -1;
        for(auto [u,v,w] : edges){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                cycle_node = v;
                relaxant[v] = u;
            }
        }
    }

    if(cycle_node == -1){
        cout << "NO" << endl;
    }
    else{
        
        for(int i = 0; i < n; i++){ 
            cycle_node = relaxant[cycle_node];
        }

        vector<int>cycle;
        int curr = cycle_node;
        cycle.push_back(curr);
        curr = relaxant[curr];
        while(curr != cycle_node){
            cycle.push_back(curr);
            curr = relaxant[curr];
        }
        cycle.push_back(curr);
         
         
        cout << "YES" << endl;
        reverse(cycle.begin() , cycle.end());
        for(int elm : cycle){
            cout << elm << " ";
        }
    } 
}


    

    
        
    



    


    // Vth iteration finding negative cycles nodes;

