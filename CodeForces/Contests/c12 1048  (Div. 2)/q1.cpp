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
        int a , b;
        cin >> a >> b;
        if(a == b){
            cout << 0 << endl;
        }
        else if(a % b == 0 || b % a == 0){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
}