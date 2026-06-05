#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
 //defining template when duplicate elements are also used
template <class T> using ordered_set = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

bool cmp(vector<int>&a , vector<int>&b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(3 , 0));

    for(int i= 0; i < n; i++){
        int x , y;
        cin >> x >> y;

        arr[i] = {x,y, i};
    }

    sort(arr.begin(), arr.end(), cmp);

    vector<int>any_contain(n , 0);
    vector<int>contains_any(n , 0);
    ordered_set<int> st1; // store end prev ranges to get order of that element
    
     
    for(int i = 0; i < n; i++){
        
        int currend = arr[i][1];

        int index = st1.order_of_key(currend);

        any_contain[arr[i][2]] = ((int)(st1.size()) - index);

        st1.insert(currend);
    }

    ordered_set<int> st2; // store end prev ranges to get order of that element
   
    for(int i = n - 1; i >= 0; i--){
    
        int currend = arr[i][1];
        int index = st2.order_of_key(currend + 1);

        contains_any[arr[i][2]] = (index);
        st2.insert(currend);
    }

    for(int i = 0; i < n; i++) cout << contains_any[i] << " ";

    cout << endl;

    for(int i = 0; i < n; i++) cout << any_contain[i] << " ";
}