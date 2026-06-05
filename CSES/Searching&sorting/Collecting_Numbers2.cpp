#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int , int>> arr(n + 1); // {elm , postn}
    vector<int>elmarr(n + 1);


    for(int i= 1; i <= n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
        elmarr[i] = arr[i].first; // to get the elm by position so that by elm i can get the postion of that element in arr(pair {elm , index})
    }

    sort(arr.begin(), arr.end());

    int rounds = 1;
    for(int i= 1; i < n; i++){
         if(arr[i].second > arr[i + 1].second){
            rounds++;
         }
    }

    for(int i = 0; i < m; i++){
        int a , b;
        cin >> a >> b;

        int elm1 = elmarr[a];
        int elm2 = elmarr[b];

        int ind1 = arr[elm1].second;
        int ind2 = arr[elm2].second;

        // it wil only affect when arr[b] will be on the left side of its smaller numenr arr[b] - 1 after swap
        if(elm1 < elm2){
            if(ind1 < ind2) 
                rounds++; 
            else
                rounds--;  
        }
        else{
            if(ind1 < ind2)
                rounds--;       
            else
                rounds++;    
        }

        // perform swap

        swap(arr[elm1].second , arr[elm2].second);
        swap(elmarr[a] , elmarr[b]);

        cout << rounds << endl;

    }

    

    

}