#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<int> find_max(vector<int>&arr){
    int n = arr.size();

    vector<pair<int , int>> temp(n);

    for(int i = 0; i < n; i++){
        temp[i].first = arr[i];
        temp[i].second = i;
    }

    sort(temp.rbegin(), temp.rend());

    vector<int> ans(3);

    for(int i= 0;i < 3; i++){
        ans[i] = temp[i].second;
    }

    return ans;   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> a(n) , b(n) , c(n);

        for(int i =0; i < n; i++) cin >> a[i];
        for(int i =0; i < n; i++) cin >> b[i];
        for(int i =0; i < n; i++) cin >> c[i];

        vector<int> maxa = find_max(a);
        vector<int> maxb = find_max(b);
        vector<int> maxc = find_max(c);

        int ans = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    int x = maxa[i];
                    int y = maxb[j];
                    int z = maxc[k];
                    if(x != y && y != z && x != z){
                        ans = max(ans , a[x] + b[y] + c[z]);
                    }
                }
            }
        }

        cout << ans << endl;
    }
}