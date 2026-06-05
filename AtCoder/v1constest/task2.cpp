#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;
    cin >> n;

    vector<pair<int , int>> a(n);

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a[i] = {temp , i};

    }

    sort(a.begin(), a.end());

    for(int i = 0; i < 3; i++){
        cout << a[i].second + 1 << ' ';
    }
}