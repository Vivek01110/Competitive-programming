#include<bits/stdc++.h>
using namespace std;
void two_duplicate(vector<int> arr){
    int n = arr.size();

    int xor_val = 0;

    for(int i = 0; i < n; i++){
        xor_val ^= arr[i];
    }

    for(int i = 1; i <= n-1; i++){
        xor_val ^= arr[i];
    }

    int set_bit = xor_val& - xor_val;

    int x = 0;
    int y = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] & set_bit){
            x ^= arr[i];
        }
        else{
            y^= arr[i];
        }
    }

    for(int i = 1; i <= n-1; i++){
        if(i & set_bit){
            x ^= i;
        }
        else{
            y^= i;
        }
    }

    if(count(arr.begin() , arr.end(), x) > 1){
        cout << x-1 << " " << y-1 <<endl;
    }
    else{
        cout << y-1 << " " << x-1 <<endl;
    }

   
}
int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        int xor_val = 0;

        vector<int>arr(n+2 , 0);

        for(int i = 0; i < n+2; i++){
            cin >> arr[i];
        }

        two_duplicate(arr);
    }
}
// 1
// 5
// 1 2 3 2 4 3 5 