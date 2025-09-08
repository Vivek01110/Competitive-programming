#include<iostream>
using namespace std;

int main(){


    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }

    if(n <= 3){
        cout << "NO SOLUTION";
        return 0;
     }

     int odd;
     int even;

     if(n&1) {
        odd = n;
        even = n - 1;
     }
    else{
        odd = n - 1;
        even = n;
    }

    for(int i = 2; i <= even; i+=2){
        cout << i << " ";
    }

    for(int i = 1; i <= odd; i += 2){

        cout << i;

        if(i != odd){
            cout << " ";
        }
    }


}

/*
5
4
3
2
1
1001
2002
*/