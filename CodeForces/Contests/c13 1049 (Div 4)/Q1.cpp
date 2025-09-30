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
        int x, n;
        cin >> x >> n;

        cout << ((n&1) ? x : 0 )<< endl;
    }
}