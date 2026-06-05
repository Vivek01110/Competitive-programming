#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int , int>mp;
   
    for(int i= 0; i < n; i++){
        int elm;
        cin >> elm;

        mp[elm]++;
    }
    ll cnt = 1;
    for(auto itr : mp){
        ll freq = itr.second;

        cnt *= (freq + 1);
        cnt %= MOD;
    }

    cout << cnt - 1 << endl;

    

}
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     vector<pair<int , int>>a(n);
   
//     for(int i= 0; i < n; i++){
//         cin >> a[i].first;
//         a[i].second = i; 
//     }

//     sort(a.begin(), a.end());
//     ll size = 1;
//     for(int i = 1; i < n; i++){
//         if(a[i].first != a[i].first){
//             size++;
//             continue;
//         }

//         if(a[i].second == a[i - 1].second && abs(a[i].second - a[i - 1].second) > 1){
//             size++;
//         }
//     }


//     ll power = 1;

//     for(int i = 1; i <= size; i++){
//         power *= (ll)2;
//         power %= MOD;
//     }

//     cout << power - 1<< endl;

// }