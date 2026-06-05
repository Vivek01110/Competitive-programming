#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int>a(n);

    for(int i= 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int cnt = 1;
    for(int i= 0; i < n - 1; i++){
        if(a[i] != a[i + 1]){
            cnt++;
        }
    }

    cout << cnt << endl;
}