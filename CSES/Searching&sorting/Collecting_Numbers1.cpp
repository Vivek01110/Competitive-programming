#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int , int>> arr(n + 1);

    for(int i= 1; i <= n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());
    int cnt = 1;
    for(int i= 1; i < n; i++){
         if(arr[i].second > arr[i + 1].second){
            cnt++;
         }
    }

    cout << cnt << endl;

}