#include<iostream>

using namespace std;

int main(){
    long long n;
    cin >> n;

   int cnt = 0;

    while(n != 1){
        cout << n << " ";
        if(n&1) n = (long long)((long long )n*3 + 1);
        else n /= 2;

        
    }

    cout << 1;

}