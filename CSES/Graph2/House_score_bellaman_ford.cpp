// bellaman ford algorithm

// relax all edges v- 1 times 
//    if(dist[u] + w < dist[v]) dist[v] = dist[u] + w

//why v - 1 times
// After 1st iteration finds shortest path atmost 1 edges (path having  1 edge)
// After 2nd iteration finds shortest path atmost 2 edges(path having  2 edge)
// After ith iteration finds shortest path atmost i edges
// After (v- 1)th iteration finds shortest path atmost v - 1 edges


//detect negative
// after relaxing all edges  v - 1 times if any  if any edges is relaxed  in vth iteration 
// that means there is a negative cycle present

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

vector<vector<int>> make_adj(int n,vector<vector<ll>> &edges){
    vector<vector<int>>adj(n + 1);

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }
    return adj;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m;
    cin >> n >> m;

    vector<vector<ll>> edges;
    vector<ll> dist(n + 1, LLONG_MIN);
    dist[1] = 0;

    for(int i = 0; i < m; i++){
        int a , b , c;
        cin >> a >> b >> c;

        edges.push_back({a,b,c});
   
    }
    

    int V = n;
    bool cycle_present = false;
    set<int> st;
     
    for(int i = 1; i <= V; i++){
        for(auto &edge : edges){
            ll u = edge[0];
            ll v = edge[1];
            ll w = edge[2];

            if(dist[u] == LLONG_MIN) continue;

            if(dist[u] + w > dist[v]){
                dist[v] = dist[u] + w;
                if(i == V){
                    cycle_present = true; // positive cycle detection
                    st.insert(v);
                }
            }
        }

        
    }

    if(!cycle_present) cout << dist[n] << endl;
    else{

        vector<vector<int>>adj = make_adj(n,edges);
        vector<bool>visited(n + 1 , false);
        queue<int>q;
        queue<int>cycle_q; // cycel node which are reachable from 1

        q.push(1);
        visited[1] = true;

        while(!q.empty()){
            int elm = q.front();
            q.pop();

            if(st.count(elm)){
                cycle_q.push(elm);
            }

            for(int nbr : adj[elm]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

        bool can_reach_n = false;
        visited.assign(n + 1 , false);
        while(!cycle_q.empty()){
            int elm = cycle_q.front();
            cycle_q.pop();

            if(elm == n){
               can_reach_n = true;
               break; 
            }

            for(int nbr : adj[elm]){
                if(!visited[nbr]){
                    cycle_q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }


        if(cycle_present && can_reach_n){
            cout << -1 << endl;
        }
        else{
            cout << dist[n] << endl;
        }

    }
}

































        // q.push(cycle_node);

        // vector<bool>visited(n + 1 , false);
        // visited[cycle_node] = true;
        // bool canreach_to_n = false;

        // while(!q.empty()){
        //     int elm = q.front();
        //     q.pop();

        //     if(elm == n){
        //         canreach_to_n = true;
        //         break;
        //     }

        //     for(int nbr : adj[elm]){
        //         if(!visited[nbr]){
        //             q.push(nbr);
        //             visited[nbr] = true;        
        //         }
        //     }
            
        // }

        // while(!q.empty()) q.pop();

        // q.push(1);
        // visited.assign(n + 1,  false);
        // visited[1] = true;
        // bool can_reach_to_cycle = false;

        // queue<int>cycle_q;

        // while(!q.empty()){
        //     int elm = q.front();
        //     q.pop();

        //     if(st.count(elm)){
        //         cycle_q.push(elm);  
        //     }

        //     for(int nbr : adj[elm]){
        //         if(!visited[nbr]){
        //             q.push(nbr);
        //             visited[nbr] = true;        
        //         }
        //     }
            
        // }

//         if(cycle_present && canreach_to_n && can_reach_to_cycle){
//             cout << -1 << endl;
//         }
//         else{
//             cout << dist[n] << endl;
//         }


//     }
// }




















// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007

// vector<vector<int>> make_adj(int n,vector<vector<ll>> &edges){
//     vector<vector<int>>adj(n + 1);

//     for(auto edge : edges){
//         int u = edge[0];
//         int v = edge[1];

//         adj[u].push_back(v);
//     }
//     return adj;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n , m;
//     cin >> n >> m;

//     vector<vector<ll>> edges;
//     vector<ll> dist(n + 1, LLONG_MIN);
//     dist[1] = 0;

//     for(int i = 0; i < m; i++){
//         int a , b , c;
//         cin >> a >> b >> c;

//         edges.push_back({a,b,c});
   
//     }
    

//     int V = n;
//     bool cycle_present = false;
//     int cycle_node = -1;
//     bool flag = false;
//     for(int i = 1; i <= V; i++){
//         for(auto &edge : edges){
//             ll u = edge[0];
//             ll v = edge[1];
//             ll w = edge[2];

//             if(dist[u] == LLONG_MIN) continue;

//             if(dist[u] + w > dist[v]){
//                 dist[v] = dist[u] + w;
//                 if(i == V){
//                     cycle_node = v;
//                     cycle_present = true; // positive cycle detection
//                     flag = true;
//                 }
//             }
//         }

        
//     }

//     if(!cycle_present) cout << dist[n] << endl;
//     else{

//         vector<vector<int>>adj = make_adj(n,edges);

//         queue<int>q;
//         q.push(cycle_node);

//         vector<bool>visited(n + 1 , false);
//         visited[cycle_node] = true;
//         bool canreach_to_n = false;

//         while(!q.empty()){
//             int elm = q.front();
//             q.pop();

//             if(elm == n){
//                 canreach_to_n = true;
//                 break;
//             }

//             for(int nbr : adj[elm]){
//                 if(!visited[nbr]){
//                     q.push(nbr);
//                     visited[nbr] = true;        
//                 }
//             }
            
//         }

//         while(!q.empty()) q.pop();

//         q.push(1);
//         visited.assign(n + 1,  false);
//         visited[1] = true;
//         bool can_reach_to_cycle = false;

//         while(!q.empty()){
//             int elm = q.front();
//             q.pop();

//             if(elm == cycle_node){
//                 can_reach_to_cycle = true;
//                 break;
//             }

//             for(int nbr : adj[elm]){
//                 if(!visited[nbr]){
//                     q.push(nbr);
//                     visited[nbr] = true;        
//                 }
//             }
            
//         }

//         if(cycle_present && canreach_to_n && can_reach_to_cycle){
//             cout << -1 << endl;
//         }
//         else{
//             cout << dist[n] << endl;
//         }


//     }
// }