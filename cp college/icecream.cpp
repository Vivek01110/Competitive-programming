#include<iostream>
using namespace std;

bool ispossible(int m){
    int fivenotes = 0;
    int tennotes = 0;
    

    if(m == 0) return true;

    for(int i = 0; i < m; i++){
        int note;
        cin >> note;

        if(note == 5){
            fivenotes++;
        }
        else if(note == 10){
            tennotes++;
            fivenotes--;
        }
        else{// if note is twenty
            if(tennotes > 0){
                tennotes--;
                fivenotes--;
            }
            else{
                fivenotes-=3;
            }
        }

        if(fivenotes < 0)
            return false;
    }

    return true;
}
int main(){
    int T;
    cin >> T;

    while(T--){
        int m;
        cin >> m ;

        cout << ispossible(m) << endl;
    }
}



// testcases
/*
5
5
5 5 5 10 20
3
5 10 20
4
10 5 10 20
0
2
5 20 

*/


