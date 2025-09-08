// given an array of negative and positive numbers , find the min product of subset of three numbers .
// Note : single can also be on the answer


#include<bits/stdc++.h>
using namespace std;

int min_product(vector<int>arr){
    sort(arr.begin() , arr.end());
    

    if(arr.size() == 0) return 0;
    if(arr.size() == 1) return arr[0];
    

    if(arr[0] > 0 && arr[1] > 0){
        if(arr[0] < arr[1]){
            return arr[0];
        }
        else return arr[1];
    } 
    else{ 
        return arr[0]*arr[1];
    }

    
    int negatives = 0;
    int minimum = INT_MAX;
    int maximum = 0;

    int maximum_pos = 0;

    for(int i = 0; i < 3; i++){
        if(arr[i] < 0){
            negatives++;
        }

        if(minimum > arr[i]){
            minimum = arr[i];
        }

        if(maximum < arr[i]){
            maximum = arr[i];
        }
    }

    if(negatives == 0){
        return minimum;
    }
    else if(negatives == 1 || negatives == 3){
        return arr[0]*arr[1]*arr[2];
    }
    else{
        return minimum*maximum;
    }


}
int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> arr(n);
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << min_product(arr);

        


    }
}
/*
3
4
-3 2 4 5
4
-3 2 -4 5
4
-3 2 -4 -5

*/