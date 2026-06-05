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
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin() ,a.end() ,greater<int>());

        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }

        cout << endl;
    }
}