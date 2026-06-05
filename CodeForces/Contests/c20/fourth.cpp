#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
pair<int, int> ans;
long long mindist = LONG_LONG_MAX;
void solve(int i ,   vector<int> p,  vector<int> q,ll x , ll y){
    if(i == 31){
       
        long long pnum = 0;
        long long qnum = 0;
        for(int i = 0; i < 31; i++){
            pnum = pnum*2 + (ll)p[i];
            qnum = qnum*2 + (ll)q[i];
        }
        long long dist = abs(x - pnum) + abs(y - qnum);
        if(mindist > dist){
            mindist = dist;
            ans = {pnum , qnum};
        }

        return;
    }

    p[i] = 1;
    solve(i + 1 , p,q, x,y);
    p[i] = 0;

    q[i] = 1;
    solve(i + 1 , p, q , x , y);
    q[i] = 0;

    solve(i + 1, p , q , x , y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        ll x , y;
        cin >> x >> y;
        
        vector<int> p(31, 0);
        vector<int> q(31, 0);
        solve(0,p,q,x,y);
        cout << ans.first << " " <<  ans.second << endl;
        
    }
}