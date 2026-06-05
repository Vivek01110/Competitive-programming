#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>>a(n); // sort based on deadline
    vector<vector<int>> b(n); // sort based on duration
    vector<bool>isdone(n, false);
    

    for(int i = 0; i < n; i++){
        int dur , dead;
        cin >> dur >> dead;

        a[i] = {dead, dur , i};
        b[i] = {dur ,dead, i};
    }

    sort(a.begin() , a.end());
    sort(b.begin(), b.end());

    

    

    int finishtime = 0;
    ll reward = 0;

    for(int i = 0; i < n; i++){
        
    }





}