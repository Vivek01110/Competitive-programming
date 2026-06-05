#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

long long solve(int i, int m , int n , vector<int> &a){
    if(i == n){
        return 1;
    }

    if(i > 0 && a[i] != 0){
        int diff = abs(a[i - 1] - a[i]);
        if(diff > 1) return 0;
    }

    if(i > 0 && a[i] == 0){
        
    }

     
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int>a(n);

    for(int i=0; i < n; i++) cin >> a[i];

    cout << solve(0 , m, n ,a);

}