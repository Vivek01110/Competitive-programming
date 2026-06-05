#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<ll, ll>> a(n); // {lv time , arr time}
    
    for(int i= 0; i < n; i++){
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(), a.end());
    //sorted based on leaving time
    int cnt = 1;
    int prevet = a[0].first;
    for(int i = 1; i < n; i++){
        int leavtime = a[i].first;
        int arrtime = a[i].second;

        if(arrtime >= prevet){
            cnt++;
            prevet = leavtime;
        }
    }

    cout << cnt << endl;
}