#include<bits/stdc++.h>

using namespace std;
int missing_val(vector<int> arr){
    int n = arr.size();
    int xorval = 0;
    for(int i = 0; i < n; i++){
        xorval ^= arr[i];
    }


    for(int i = 1; i <= n; i++){
        xorval ^= i;
    }

    return xorval;
}
int main(){
    int T;
    cin >>T;
    
    while(T--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }

        cout<<missing_val(arr);
    }
    
}