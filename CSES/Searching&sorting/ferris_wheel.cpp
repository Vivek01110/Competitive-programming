#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n , x;
    cin >> n >> x;

    vector<ll>p(n);

    for(int i= 0;  i< n; i++) cin >> p[i];

    sort(p.begin(), p.end());
    
    int i = 0;
    int j = n -1;
    int cnt = 0;
    while(i <= j){
        if(p[i] + p[j] <= x){  
            i++;
            j--;
        }
        else{
            j--;
        }
        cnt++;
    }

    cout << cnt;
}