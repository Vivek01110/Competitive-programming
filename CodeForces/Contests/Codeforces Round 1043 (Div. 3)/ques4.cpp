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
        int k;
        cin >> k;
        
        ll s = 1;
        ll e = 1000000000000000;
        int num = 0;
        while(s < e){
            ll mid = s + (e - s)/2;
            ll mid_digit = digit(mid);
            if(mid_digit == k){
                num = mid;
            }
            else if(mid_digit < k){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }


        cout << ((ll) (num/2)*(num + 1)) << endl;
    }
}