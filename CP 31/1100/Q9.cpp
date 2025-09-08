#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
//  observations

// we need only traverse first half in case of brute force
// 1. a <= b
// 2. b >= n/2
// 3. b <= n - 1
// 4. b%a == 0 // beacause then lcm(a , b)  will be b, and its minimum thats why
// 5. n%a = (a + b)%a
    //   n % a = (a%a + b%a + a) % a
    // n%a = (0 + 0 + a) % a
    // n%a = 0;

 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

      while(T--){
        int n;
        cin>> n;
        int ans = INT_MAX;
        int a = 1;
        int b = n - 1;
        for(int i = 2; i <= sqrt(n); i++ ){
             
            if(n%i == 0){
                a = n/i;
                break;
            } 
        }

        cout << a << " " << n - a << endl;
    }
    
  
}

// Brute Force

// int gcd(int a , int b){
    
//     while(b != 0){
//         int temp = a;
//         a = b;
//         b = temp % b;
//     }

//     return a;
// }
// int LCM(int a , int b){
//     // LCM(a, b) = (a x b) / GCD(a, b)

//     return a*b/ gcd(a,b);
// }
// while(T--){
    //     int n;
    //     cin>> n;
    //     int ans = INT_MAX;
    //     int a = 1;
    //     int b = n - 1;
    //     for(int i = 1; i <= n/2; i++ ){
    //         int lcm = LCM(i , n - i);
    //         if(ans > lcm){
    //             a = i;
    //             b = n - i;

    //             ans = lcm;
    //         } 
    //     }

    //     cout << a << " " << b << endl;
    // }