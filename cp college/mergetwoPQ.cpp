#include<bits/stdc++.h>
using namespace std;

priority_queue<int> merge(priority_queue<int>A , priority_queue<int>B){
    if(B.empty()) return A;
    if(A.empty()) return B;


    while(!B.empty()){
        A.push(B.top());
        B.pop();
    }

    return A;
}

void print_PQ(priority_queue<int>A){
    if(A.empty()){
        cout << "NULL";
    }

    while(!A.empty()){
        cout << A.top() << " ";
        A.pop();
    }
    cout << endl;
}


int main(){

    int T;
    cin >> T;

    while(T--){
        int size_A , size_B;
        cin >> size_A >> size_B;

        priority_queue<int>A;
        priority_queue<int>B;

        for(int i = 0; i < size_A; i++){
            int temp;
            cin >> temp;

            A.push(temp);

        }

        for(int i = 0; i < size_B; i++){
            int temp;
            cin >> temp;

            B.push(temp);
            
        }

        A = merge(A , B);

        print_PQ(A);
 

    }
}
/*
4
3 5
2 3 4
7 5 3 6 78
0 4
8 5 5 3
3 0
3 78 3
0 0

*/
