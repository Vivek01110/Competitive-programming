#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<pair<long long, int>>a(n);

        for(int i = 0; i < n; i++){
             cin >> a[i].first;
             a[i].second = i;
        }

        sort(a.begin(), a.end());

        vector<long long> pref(n);

        pref[0] = a[0].first;
        for(int i = 1; i < n; i++) pref[i] = ((ll)a[i].first + pref[i - 1]);
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
             
            int j = i;
            int elms = i;

            while(j < n){
                pair<long long , int> temp = {pref[j] + 1,INT_MIN};
                int index = lower_bound(a.begin() , a.end(), temp) - a.begin();
                index--;
                if(index == j){
                    break;
                }

                elms += (index - j);  
                j = index;

            }

            ans[a[i].second] = elms;

        }

        for(int i= 0; i < n; i++){
            cout << ans[i] << " ";
        }

        cout << endl;
    }     
}
