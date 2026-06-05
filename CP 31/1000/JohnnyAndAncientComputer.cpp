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
        ll a , b;
        cin >> a >> b;
        
        if(a == b){
            cout << 0 << endl;
            continue;
        }
        ll opr = 0;
        ll num = a;
        bool ispossible = true;
        while(num != b){
            if(num > b){
                if(num%8 == 0 && num/8 >= b){
                    num /= 8;
                    opr++;
                }
                else if(num%4 == 0 && num/4 >= b){
                    num /= 4;
                    opr++;
                }
                else if(num%2 == 0 && num/2 >= b){
                    num /= 2;
                    opr++;
                }
                else{
                    ispossible =false;
                    break;
                }
            }
            else{
                if(num*8 <= b){
                    num *= 8;
                    opr++;
                }
                else if(num*4 <= b){
                    num*= 4;
                    opr++;
                }
                else if(num*2 <= b){
                    num*= 2;
                    opr++;
                }
                else{
                    ispossible = false;
                    break;
                }
            }
        }

        cout << ((ispossible) ? opr : -1) << endl;
        
    }
}