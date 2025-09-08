#include<iostream>
using namespace std;
#define MOD 1000000007
long long power(int a , int b){
    if(a == 0) return 0;
    if(b == 1) return a;

    if(b&1){
        return ((long long)a*power(a,b-1))%MOD;
    }
    else{
        long long t = power(a,b/2)%MOD;
        return ((long long)t*t)%MOD;
    }
}
int main(){
    int n;
    cin >> n;

    cout << power(2 , n);
}