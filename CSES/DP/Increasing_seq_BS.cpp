#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int>a(n);
    

    for(int i= 0; i < n; i++) cin >> a[i];
    
    vector<int>temp;
    for(int i= 0; i < n; i++){
        if(temp.size() == 0){
            temp.push_back(a[i]);
        }
        else if(temp.back() < a[i]){
            temp.push_back(a[i]);
        }
        else{
            
            auto it = lower_bound(temp.begin(), temp.end(), a[i]);
            *it = a[i];
        }
    }

    cout << temp.size() << endl;

}