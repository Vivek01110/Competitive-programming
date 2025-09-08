#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // vector<int> xr(1000001, 0);
    // for(int i = 1; i <= 1000000; i++){
    //     xr[i] = i^xr[i - 1];
    //     // cout << xr[i] << " ";
    // }
//  x till n
    // n%4 == 0 x = n
    // n%4 == 1 x = 1;
    //n%4 == 2  x = n + 1;
    //n%4 == 3 x = 0


    int T;
    cin >> T;
    
    while(T--){
        ll a , b;
        cin >> a >> b;

        // int x = xr[a - 1];
        ll x = 0;

        if((a - 1)%4 == 0)  x = (a - 1);
        else if( (a - 1)%4 == 1) x = 1;
        else if ((a - 1)%4 == 2)  x = a;
        else if((a - 1)%4 == 3) x = 0;
        
        if(x == b){
            cout << a << endl;
        }
        else if((x^b) != a){ //  if  x != b
            cout << a + 1<< endl;
        }
        else{
            cout << a + 2 << endl;
        }
        
    }
}