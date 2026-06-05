#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void solve(vector<pair<int , int>> &a , int x){
    
    int s = 0;
    int e = a.size() - 1;
    
    while(s < e){
        int sum = a[s].first + a[e].first;

        if(sum == x){
            cout << a[s].second << " " <<  a[e].second;
            return;
        }
        else if(sum < x){
            s++;
        }
        else{
            e--;
        }
    }

    cout << "IMPOSSIBLE";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;

    vector<pair<int ,int>>a(n);

    for(int i=0 ; i< n; i++ ){
        cin >> a[i].first;
        a[i].second = i + 1;
    } 

    sort(a.begin(), a.end());

    solve(a,x);
}