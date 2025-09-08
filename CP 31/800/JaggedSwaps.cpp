#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        if(a[0] == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

      

        
    }
}