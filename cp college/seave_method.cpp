#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


vector<bool> seive_Method(int m , int n){
    if(m > n) cout << "Invalid"<<endl;
    if(m == n) cout <<"0"<<endl;
    vector<bool> arr(n+1 , true);
    arr[0] = false;
    arr[0] = false;

    for(int i = 2; i <= sqrt(n); i++){
        if(arr[i]){  
            for(int j = i*i; j <= n; j += i){
                arr[j] = false;
            }
        }
    }

    return arr;
}
int main(){

    int t;
    cin >> t;

    while(t--){
    int m , n;
    // cout<<"enter the value of m"<<endl;
    cin>>m;
    // cout<<"enter the value of n"<<endl;
    cin>>n;
    
    if(m == 0) cout << 0 << 1;
    if(m == 1) cout << 1;

   vector<bool> arr =  seive_Method(m , n);
   for(int i = m; i <= n; i++){
        if(arr[i]){
            cout << i << " ";
        }

   }
   cout << endl;
    }
}

// 7
// 0 1
// 1 0
// 0 0
// 23 10
// 40 120
// 1024 2048
// 69 13