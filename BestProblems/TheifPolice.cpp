/*
    Author : Vivek
    
*/

/*
Problem : 

    1) One Police {1} ,can catch only one theif {0}
    2) polic can catch a theif if it is atmost k distance away

    find the maximum number of theif can be caught

    police can catch kth theif


    
*/

#include<bits/stdc++.h>
using namespace std;


int solve(int k , vector<int> &arr){
    int n = arr.size();

    vector<int> police;
    vector<int> theif;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0){
            theif.push_back(i);
        }
        else{
            police.push_back(i);
        }
    }

    int p = 0;
    int t = 0;

    int cnt = 0;

    while(p < police.size() && t < theif.size()){
        if(abs(police[p] - theif[t]) <= k){
            cnt++;
            p++;
            t++;
        }
        else{
            if(police[p] < theif[t]) p++;
            else t++;
        }
    }

    return cnt;  
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n, k;
        cin >> n >> k;


        vector<int> arr(n);

        for(int i= 0; i < n; i++){
            cin >> arr[i];
        }
        
        cout << solve(k , arr) << endl;

    }
}

// TestCases

/*
10
18
3
1010101010101001

*/