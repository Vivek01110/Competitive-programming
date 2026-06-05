#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int>t(n);
    vector<int>cust(m);

    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < m; i++) cin >> cust[i];

    multiset<int>mst(t.begin(), t.end());
    int cnt = 0;
    for(int i = 0; i < m; i++){
        
        auto itr = mst.lower_bound(cust[i]);

        if(*itr == cust[i]){
            cout << *itr << endl;
            mst.erase(itr); 
            continue;
        }

        if(itr == mst.begin()){
            cout << -1 << endl;
            continue;
        }
        else{
            itr--;
            cout << *itr << endl;
            mst.erase(itr);
        }
    }


}