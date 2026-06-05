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

        vector<pair<int , int>>a(n); // freq , bulding nu
        for(int i = 0; i < n;i++){
            
            cin >> a[i].first;

            a[i].second = i + 1; 
           
        }

        sort(a.begin() , a.end());

        vector<int> ans(n + 1, 0);
        int mid = n/2;
        int ans = 0;
        int left = 0;
        int right = 0;
        for(int i = n - 1; i >= 0; i--){
            if(i % 2 == 0){
                ans[a[i].second] = mid - left - 1;
                int dist = (mid - left - 1);
                left++;
                dist = dist < 0 ? dist*(-1) : dist;
                ans += 2*dist;
            }
            else{
                left.push_back(right.size() - mid + 1);
                int dist = (right.size() - mid + 1);
                ans += 2*dist;
            }
        }

        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }

        cout << endl;

        
    }
}