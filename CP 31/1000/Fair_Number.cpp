#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
bool isfair(ll num){
    ll n = num;
    while(num){
        ll digit = num%10;
        num = num/10;
        if(digit > 0 && n%digit != 0){
            return false;
        }
    }
   

    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        long long n;
        cin >> n;

        
        while(!isfair(n)){
            n += 1; 
        }

        cout << n << endl;
    }
}