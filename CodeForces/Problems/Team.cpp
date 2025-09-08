#include<iostream>
using namespace std;

int main(){
    int n;
    cin>> n;
    int problems = 0;
    while(n--){
        int a , b , c;
        cin >> a >> b >> c;

        if(a && b || b && c || a && c) problems ++; 

    }

    cout << problems;

} 