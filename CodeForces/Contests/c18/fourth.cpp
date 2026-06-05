#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        ll n, m , h;
        cin >> n, m , h;

        vector<int> a(n);

        for(int i = 0; i < n; i++) 
            cin >> a[i];

        for(int i = 0; i < m; i++){
            
        }

        

        


    }
}




































// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;

//     while(T--){
        
//         ll n, m , h;
//         cin >> n >> m >> h;

//         vector<ll> a(n);

//         vector<ll> upd(n , -1);

//         for(ll i = 0; i < n; i++){
//             cin >> a[i];
//         }

//         vector<ll> val = a;
//        int lastc = -1;
//         for(int i = 0; i < m; i++){
//             ll b,c;
//             cin >> b >> c;
//             --b;

//             if(upd[b] < lastc){
//                 val[b] = a[b];
//                 upd[b] = i;
//             }
//             val[b] += c;

//             if(val[b] > h){
//                val[b] = a[b];
//                 lastc = i;
//                 upd[b] = i; 

//             }
//             else upd[b] = i;
            
//         }

//         for(ll i = 0; i < n; i++){
//             if(upd[i] >= lastc){
//                 cout << val[i] << " ";
//             }
//             else{
//                 cout << a[i] << " ";
//             }
           
//         }

//         cout << endl;

        
//     }
// }
// TLE
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;

//     while(T--){
//         ll n, m , h;
//         cin >> n >> m >> h;

//         vector<ll> a(n);

//         for(ll i = 0; i < n; i++){
//             cin >> a[i];
//         }
//         vector<ll> temp = a;
//         for(int i = 0; i < m; i++){
//             ll index,c;
//             cin >> index >> c;
//             index--;
//             if((temp[index] + c) > h){
//                 temp = a; 
//             }
//             else{
//                 temp[index] += c;
//             }
//         }

//         for(ll i = 0; i < n; i++){
//             cout << temp[i] << " ";
//         }

//         cout << endl;
//     }
// }