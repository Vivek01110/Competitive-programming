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

        vector<int> p(n);

        for(int i= 0; i < n; i++){
            cin >> p[i];
        }

        for(int i = 0; i < n; i++){
            cout << n + 1 - p[i] << " ";
        }

        cout <<endl;

    }
}