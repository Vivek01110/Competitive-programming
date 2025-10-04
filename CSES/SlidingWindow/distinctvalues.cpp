#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void window_distinct(vector<int>&arr ,int k){
    int n = arr.size();

    unordered_map<int , int>mp;
    int distinctval = 0;
    

    for(int i = 0; i < n; i++){
        if(mp[arr[i]] == 0){  
            distinctval++; 
        }

        mp[arr[i]]++;

        if(i >= k){
            mp[arr[i - k]]--;

            if(mp[arr[i - k]] == 0){
                distinctval--;
            }

        }

        if(i >= k - 1){
            cout << distinctval << " ";
        }
    }
    
   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
       cin >> arr[i];
    }

   window_distinct(arr  , k);
}