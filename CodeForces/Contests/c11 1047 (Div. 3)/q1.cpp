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
        int k , x;
        cin >> k >> x;
        
        for(int i= 0; i < k; i++){
            x *= 2;
        }

        cout << x << endl;
    }
}