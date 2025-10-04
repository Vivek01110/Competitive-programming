#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while (t--) {
        int n;
         cin >> n;
        set<int> s;
        
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x > 0) s.insert(x);
        }
        int D = (int)s.size();
        // Each distinct positive value needs one Increase.
        // For each smaller distinct value we need one Smash between increases.
        // Total = D + (D - 1) = 2*D - 1
        if (D == 0) cout << 0 << '\n';
        else cout << 2 * D - 1 << '\n';
    }
    return 0;
}
