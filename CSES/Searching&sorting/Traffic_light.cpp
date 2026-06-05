#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    vector<int>a(n);
    multiset<int>posn; // can use set as well
    multiset<ll>passglen;
    pair<int ,int> maxgap = {0, x};
    posn.insert(0);
    posn.insert(x);
    passglen.insert(x);
    vector<int>ans;
    for(int i=0; i < n; i++){
        int p;
        cin >> p;

        auto right_light = posn.upper_bound(p);
        auto left_light = right_light;
        left_light--;
        

        int left = *left_light;
        int right = *right_light;

        passglen.erase((passglen.find(right - left)));
        passglen.insert(p - left);
        passglen.insert(right - p);

        // cout << *(passglen.end()--) << " ";
        ans.push_back(*passglen.rbegin());

        posn.insert(p);
  
    }

    for(int elm : ans){
        cout << elm << " ";
    }

}