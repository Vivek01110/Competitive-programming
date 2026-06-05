#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void solve(vector<int>a){
    int n = a.size();
    if(n == 1){
        cout << a[0] << ' ';
        return;
    }

    for(int i = 1; i < n; i += 2){
        cout << a[i] << " ";
    }

    vector<int> newarr;

    if(n % 2 == 0){
        for(int i= 0; i < n - 1; i+=2)
            newarr.push_back(a[i]);  
    }
    else{
        newarr.push_back(a[n - 1]); // 

        for(int i= 0; i < n - 1; i+= 2){
            newarr.push_back(a[i]);
        }
    }

    solve(newarr);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = i + 1;

    solve(a);

}