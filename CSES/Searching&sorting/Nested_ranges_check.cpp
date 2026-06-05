#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
bool cmp(vector<int> &a , vector<int>&b){
    if(a[0] != b[0]){
        return a[0] < b[0];
    }
    else{
        return a[1] > b[1]; // sort in descend if first is arrival is equalt
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>>a(n , vector<int>(3 , 0));

    for(int i= 0 ; i < n; i++){
        cin >> a[i][0] >> a[i][1]; // {a[i][0] , a[i][1]};
        a[i][2] = i;
    }

     
    sort(a.begin(), a.end() , cmp);
    vector<int>contains_any(n , 0);
    vector<int>any_contains(n , 0);
    int prev_y = a[0][1];
    int next_y = a[n - 1][1];

    for(int i = 1; i < n; i++){
        int currx = a[i][0];
        int curry = a[i][1];
        int curri = a[i][2];

        // any containse
        if(curry <= prev_y){
            any_contains[curri] = 1;
        }

        // assigning contains any
        int lastindex = n - i - 1;
        if(a[lastindex][1] >= next_y){
            contains_any[a[lastindex][2]] = 1;
        }

        

        prev_y = max(prev_y , curry);
        next_y = min(next_y , a[lastindex][1]);
    }

    for(int i = 0; i < n; i++){
        cout << contains_any[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < n; i++){
        
        cout << any_contains[i] << " ";
    }
}