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
        int n , k;
        cin >> n >> k;

        vector<int> a(n);
        bool flag = false;
        for(int i = 0; i < n; i++){
            cin >> a[i];

            if(a[i] == k)
                flag = true;

            
        }

        cout << (flag ? "YES" : "NO") << endl;

        
    }
}