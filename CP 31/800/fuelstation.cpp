#include<bits/stdc++.h>

using namespace std;

bool can_travel(vector<int> &V, int x, int capacity){
    int n = V.size();

    for(int i = 0; i < n - 1; i++){
        int diff = V[i + 1] - V[i];

        if(diff > capacity)
            return false;
    }

    // if you cant reach first station from 0
    if(V[0] > capacity)
        return false;

    //  if you can't reach or return from x to last station
    if((x - V[n - 1])*2 > capacity)
        return false;

    return true;
}
int Binary_search(vector<int> &V, int x){
    int s = 0;
    int e = 2*x;
    int mid = s + (e - s)/2;
    while(s < e){
        if(can_travel(V , x, mid)){
            e = mid;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }

    return s;
}


int main(){
    int T;
    cin >> T;

    while(T--){
        int n, x;
        cin >> n >> x;

        vector<int> V(n);

        for(int i = 0; i < n; i++){
            cin >> V[i];
        }

        cout << Binary_search(V , x) << endl;
    }
}