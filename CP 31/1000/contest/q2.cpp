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
        cin>> n;

        vector<int>a(n);
        for(int i= 0; i < n; i++){
            cin >> a[i];
        }
        int prefixmax = a[0];
        for(int i= 1; i < n; i+=2){
            a[i] = max(a[i] , prefixmax);
            prefixmax = max(prefixmax , a[i]);   
        }
        int cnt = 0;
        for(int i= 1; i < n; i+=2){
            if(a[i - 1] > a[i]) cnt+= (a[i - 1] - a[i] + 1);

            if(a[i + 1] > a[i]) cnt += (a[i + 1] - a[i] + 1);
        }

        cout << cnt << endl;
    }
}