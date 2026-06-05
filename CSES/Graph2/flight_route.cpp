#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pii pair<ll, ll>
#define tp tuple<ll , int ,int>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        ll n, m;
        cin >> n >> m;

        vector<vector<pii>> adj(n + 1);
    
        for(int i= 0; i < m; i++){
            ll a , b , c;
            cin >> a >> b >> c;

            adj[a].push_back({b, c});
        }

        vector<vector<ll>>dist(n + 1 , vector<ll>(2, LLONG_MAX));
        dist[1][0] = 0;

        // dist[i][0] = full
        // dist[i][1] = half

        priority_queue<tp, vector<tp> ,greater<tp>>pq;

        pq.push({0,1,0});
        
        while(!pq.empty()){
            auto [currd , elm , used] = pq.top();
            pq.pop();

            if(currd > dist[elm][used]) continue;

            for(auto it : adj[elm]){
                int nbr = it.first;
                ll w = it.second;
                if(used == 0){ // full
                    
                    // Go to without using discount
                    if(dist[nbr][0] > currd + w){
                        dist[nbr][0] = currd + w;
                        pq.push({dist[nbr][0], nbr, 0});
                    }

                    // use discount
                    if(dist[nbr][1] > currd + w/2){
                        dist[nbr][1] = currd + w/2;
                        pq.push({dist[nbr][1], nbr , 1});
                    }
                }
                else{
                    //half

                    if(dist[nbr][1] > currd + w){
                        dist[nbr][1] = currd + w;
                        pq.push({dist[nbr][1], nbr, 1});
                    }
                }
            }



        }

        cout << dist[n][1] << endl;

        


    

}
































// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// #define pii pair<ll , ll>


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll n, m;
//     cin >> n >> m;

//     vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, LLONG_MAX));
    
//     for(int i= 0; i < m; i++){
//         ll a , b , c;
//         cin >> a >> b >> c;

//         adj[a][b] = min(adj[a][b] , c);
         
//     }

//     vector<pair<ll, ll>> dist(n + 1 , {LLONG_MAX, 0}); // {dist , maxprice till here}
//     vector<ll>parent(n + 1 , -1);


//     priority_queue<vector<ll>, vector<vector<ll>> , greater<vector<ll>>> pq; //{dist , elm , maxprice}

//     pq.push({0, 1,0});
//     dist[1].first = 0;
//     dist[1].second = 0;
//     long long ans = LLONG_MAX;
//     while(!pq.empty()){
//         ll currd = pq.top()[0];
//         ll elm = pq.top()[1];
//         ll mp = pq.top()[2];
//         pq.pop();

//         if(elm == n && dist[n].first != LLONG_MAX){
//             ans = min(ans , (dist[n].first - dist[n].second) + (dist[n].second)/2);
//         }



//         for(int j = 1; j <= n; j++){
//             ll nbr = j;
//             ll w = adj[elm][j];

//             if(w == LLONG_MAX) continue;

//             if(currd + w < dist[nbr].first){
//                 dist[nbr].first = currd + w;
//                 parent[nbr] = elm;
//                 dist[nbr].second = mp;
//                 pq.push({dist[nbr].first,nbr,dist[nbr].second});

//             }
//         }  
//     }
//     cout << ans << endl;

// }