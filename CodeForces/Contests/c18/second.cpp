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
        int maxi = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;

            maxi = max(maxi , temp);
        }

        cout << (long long)maxi*n << endl;
    }
}