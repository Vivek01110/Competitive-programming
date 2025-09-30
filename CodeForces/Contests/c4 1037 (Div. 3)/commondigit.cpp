#include<iostream> 
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int x;
        cin >> x;

        if(x < 10){
            cout << x << endl;
            continue;
        }

        int small_digit = 9;

        while(x){
            small_digit = min(small_digit , x%10);
            x /= 10;
        }

        cout << small_digit << endl;
    }
}

/*
9
6
96
78
122
696
1000
999
111
101

*/