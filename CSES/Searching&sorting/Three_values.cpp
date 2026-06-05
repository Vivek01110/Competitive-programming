#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void three_sum(int x ,  vector<pair<int , int>>&a){
    int n = a.size();
    bool flag = true;
    for(int k = 1; k < n - 1; k++){
        int s = 0;
        int e = n - 1;
        int sum = x - a[k].first; 

        while(s < e){
            
            int tempsum = a[s].first + a[e].first;

            if(tempsum == sum){
                cout << a[s].second << " " <<  a[k].second << ' '<< a[e].second << endl;
                flag = false;
                break;
            }
            else if(tempsum < sum){
                s++;
            }
            else{
                e--;
            }

            if(s == k) s++;
            if(e == k) e--;
        }

        if(flag == false) break;
    }

    if(flag){
        cout << "IMPOSSIBLE" << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x ;

    vector<pair<int , int>>a(n);

    for(int i= 0; i < n; i++){
        int temp;
        cin >> temp;

        a[i] = {temp , i + 1};
    }

    sort(a.begin(), a.end());

    three_sum(x,a);

}