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

        if(n == 2)
            cout << 2 << endl;
        else if(n==3)
            cout<<3<<endl;
        else{
            if(n%2 == 0){
                cout << 0 << endl;
            }
            else{
                cout<<1<<endl;
            }
  
        }
    }
}
// 15 3 3 3 3 3 => 3
//  1 // 19 2 2 2 2 2 => 0
//  2 //17 3 3 3 3 3 2 => 3 - 2 = 1
 //19 3 3 3 3 3