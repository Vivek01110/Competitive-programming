#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void two_sum(vector<int>arr ,int target){
    int n = arr.size();
    unordered_map<int , int> mp;

    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]] = i;
    }

    sort(arr.begin(), arr.end()); 

    int s = 0;
    int e = n - 1;

    while(s < e){
        int sum = arr[s] + arr[e];

        if(sum == target){
            cout << mp[arr[s]] << " " << mp[arr[e]] << endl;
        }
        else if(sum < target){
            s++;
        }
        else
            e--;
    }

    cout << -1 << " " << -1 << endl;
}

int two_sum_mp(vector<int>&arr ,int target){
    unordered_map<int ,int>mp;

    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]] = i;
    }



}
int main(){

    int t;
    cin >> t;

    while(t--){
    int n;
    cin >> n;

    int target;
    cin>>target;

    vector<int> arr(n,0);

    for(int i=0; i < n; i++){
        cin >> arr[i];   
    }

    two_sum(arr , target);

    }
     
    // TEstcase

    // 3
    // 0 
    
    


    // pair<int , int> p = two_sum(arr, target)
}