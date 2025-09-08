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
        ll a , b;
        cin >> a >> b;
        
        
        ll minopr = INT_MAX;
       

        for(ll add = 0; add < 32; add++){ // because power of two max 31 
            
            ll opr = add;
            ll temp_a = a;
            ll temp_b = b + add;

            if(temp_b == 1) continue;   

            
            
            while(temp_a > 0){
                temp_a /= temp_b;
                opr++;
            }

            minopr = min(minopr , opr);
        }

        cout << minopr << endl;

    }
}
        // if(a < b)
        //     cout << 1 << endl;
        // else if(a == b){
        //     cout << 3 << endl;
        // }
        // else{
        //     int cnt = 0;
           

        //     while(a > 0){
        //         if(a/b > 0){
        //             b++;
        //             cnt++;
        //         }

        //         a = a/b;
        //         cnt ++;     
        //     }

        //     cout << cnt << endl;
        // }

