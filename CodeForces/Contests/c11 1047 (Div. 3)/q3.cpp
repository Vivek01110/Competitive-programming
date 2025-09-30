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
     
        if(a %2 == 0 && b%2 == 0){// both even
            cout << a*b/2 + 2 << endl; 
            continue;
        }

        if(a%2 && b%2)
            cout << a*b + 1 << endl;
        else if(b%2){
            cout << -1 << endl; // b odd then its imposible to make a*k + b/k even
        }
        else if(a % 2){
            if(b % 2 == 0 && b%4)
                cout << -1 << endl;
            else
                cout << a*(b/2) + 2 << endl;
        }
    }
}

//      ll ans = -1;
        // for(ll k = b; k > 0;  k -= b){
        //     int temp_b = b;
        //     int temp_a = a;

        //     temp_a *= k;
        //     temp_b /= k;

        //     if((temp_a + temp_b) & 1 != 0){
        //         ans =  temp_a + temp_b;
        //         break;
        //     }
        // }