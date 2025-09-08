#include<bits/stdc++.h>
using namespace std;
 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n, p;
        cin >> n >> p;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vector<pair<int, int>>v(n);

        for(int i = 0; i < n; i++){
            v[i] = {b[i] , a[i]};
        }

        sort(v.begin() , v.end());

        long long totalcost = p;
         long long already_shared = 1;
        
        for(auto vill : v){
             long long canshare = vill.second;
             long long sharecost = vill.first;

            if(sharecost >= p){
                break ;
            }

            if(already_shared + canshare > n){
                totalcost += (n - already_shared)*sharecost;
                already_shared = n;
                break;
            }
            else{
                totalcost += canshare*sharecost;
                already_shared += canshare;
                
            }
        }

        totalcost += ((n - already_shared)*p);

        cout << totalcost << endl;
       
    }
}





// its not wroking for sometestcases


// to access min cost villagers
        // <cost, freq>
 //   priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;


        // for(int i = 0; i < n; i++){
        //     pq.push({b[i] , a[i]});
        // }

        // queue<pair<int , int>> q;
        // // <cost , freq>
        // auto elm = pq.top();
        // pq.pop();
        // q.push({elm.first , elm.second});

        // if(p <= elm.first){ // if p is the greater than lowest cost
        //     cout << p*n << endl;
        //     continue;
        // }

        // int totalcost = p;

        // while(!pq.empty()){
        //     int cost = q.front().first;
        //     int shares = q.front().second;
        //      q.pop();

        //     if(cost >= p){
        //         totalcost += (long long)p*pq.size();
        //         break;
        //     }
            
           

        //     while(!pq.empty() && shares > 0){
        //         auto vill = pq.top();
        //         pq.pop();

        //         q.push(vill);

        //         totalcost += cost;

        //         shares--;
        //     }
        // }

        // cout << totalcost << endl;