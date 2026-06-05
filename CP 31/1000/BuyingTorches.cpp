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
        ll x , y , k;
        cin>> x >> y >> k;

        ll total_sticks_need = (k*y + k - 1); // sticks for coals + sticks - 1 // -1 because we have already one

        ll minopr = k; // to exchange k coals

        minopr += ((total_sticks_need + x - 2)/(x- 1)); 

        cout << minopr << endl;
    }
}