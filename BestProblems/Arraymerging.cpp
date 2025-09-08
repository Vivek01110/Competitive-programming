#include<bits/stdc++.h>
using namespace std;

unordered_map<int , int> max_freq(vector<int>&arr){
    unordered_map<int , int>mp;
    int n = arr.size(); 

    int i = 0;
    while(i < n){
        int j = i + 1;
        
        while(j < n && arr[i] == arr[j])
            j++;

        if(mp.find(arr[i]) == mp.end())
            mp[arr[i]] = j - i; 
        else
            mp[arr[i]] = max(mp[arr[i]] , j - i);
             
        i = j;
    }

    return mp;
}


int max_equal_subarray(vector<int> &a ,vector<int>&b){
    int n = a.size();
    unordered_map<int , int>amap = max_freq(a); // max adjacent frequency of eaqch number
    unordered_map<int , int>bmap = max_freq(b);

    int maxans = 1;
    
    // in a_map
    for(auto p : amap){
        int elm = p.first;
        int a_freq = p.second;

        int b_freq = 0;

        if(bmap.find(elm) != bmap.end()){
            b_freq = bmap[elm];
        }

        maxans  = max(maxans , b_freq + a_freq);     
    }

    // in b_map so that remaining element also cover
    for(auto p : bmap){
        int elm = p.first;
        int b_freq = p.second;

        int a_freq = 0;

        if(amap.find(elm) != amap.end()){
            a_freq = amap[elm];
        }

        maxans = max(maxans , b_freq + a_freq);     
    }


    return maxans;
    
}
int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int>a(n) , b(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        cout << max_equal_subarray(a , b) << endl;     
    }
}

 