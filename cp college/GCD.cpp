#include<iostream> 
using namespace std;

// int gcd(int m , int n){
//     if(m == 0 || n == 0) return 0;

//     if(m == n) return m;

//     if(m > n){
//         return gcd(m -n , n);
//     }
//     else{
//         return gcd(m , n - m);
//     }
    
// }

int gcd(int m ,int n){
    if(m == 0) return n;
    if(n == 0) return m;

    return gcd(n , n%m);
}
int main(){
   
    int t;
    cin >> t;

    while(t--){
        int m , n;
    
        cin>>m;
        cin>>n;

        int gcd_value = gcd( m ,n);
        cout << gcd_value << endl;

    }
}