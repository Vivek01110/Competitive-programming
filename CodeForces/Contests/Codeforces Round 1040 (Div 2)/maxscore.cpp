#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

         
        int score = 0;

        for(int i = 0; i < N; i++){
            int temp = 0;
            cin >> temp;

            if(temp == 0) score++;
            else score += temp;
        }

        cout << score << endl;
    }
}
