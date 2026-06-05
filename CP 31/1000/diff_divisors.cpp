#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll nextprime(ll n){
    ll i = n;
    
    while(true){
       bool isprime = true;
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0){   
                isprime = false;
                break;
            }
           
        }

         if(isprime){
                return i;
            }
        i++;
    }

    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        ll d;
        cin >> d;

        long long a = nextprime(d + 1);
        long long b  = nextprime(d + a);


        cout <<(min(1ll*a*a*a , 1ll*a*b)) << endl;

    }
 
}