#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 //defining template when all elements are distinct 
template <class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

 //defining template when duplicate elements are also used
// template <class T> using Name_given_to_structure = tree<T, null_type,
// less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k;
    cin >> n >> k;

    ordered_set<int>ost;
    for(int i= 0; i < n; i++){
        ost.insert(i + 1);
    }

    int pos = k % n;

    while(!ost.empty()){
        
        int val = *ost.find_by_order(pos);
        ost.erase(val);

        cout << val << ' ';

        if(!ost.empty()){
            pos = (pos + k) % ost.size();
        }
    }
}



