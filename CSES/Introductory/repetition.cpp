#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int len = 1;
    int maxlen = 0;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == str[i + 1])
            len++;
        else{
            maxlen = max(maxlen , len);
            len = 1;
        }
    }

    cout << maxlen;
}




/*
8
ATTCGGGA
ATCGATCGA
AATTAGGGGGGGATTTA
ATCG
ATP
A
T
G


*/
// 3
// 1
// 7
// 1
// 1
// 1