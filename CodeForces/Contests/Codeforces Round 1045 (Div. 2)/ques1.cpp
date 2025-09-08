#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    bool flag = true;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        
        if(a <= b){
            if((n - b) % 2 == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            if((n - a) % 2 == 0 && (n - b) %2 == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}