#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int  max_subarray_sum(vector<int> arr){
    int n = arr.size();
     if(n == 0 )
           return -1;
        
    int sum  = 0; //sum , for the current subarray
    int  max_sum = 0; 
   

    for(int i = 0; i < n; i++){
        sum += arr[i];

        max_sum = max(max_sum , sum);

        if(sum < 0){  
            sum = 0;
        } 
    }
    
    return max_sum;
}



int main(){
    int T;
    cin>> T;

    while(T--){
        int n;
        cin >> n;
       

        vector <int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << max_subarray_sum(arr) << endl;
        
    }
}


/*
3
5
3 4 6 2 -1
5
2 6 4 2 4
0
*/

