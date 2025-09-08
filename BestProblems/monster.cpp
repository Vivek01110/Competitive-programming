#include<bits/stdc++.h> 
using namespace std;

bool cmp(pair<int , int> &a , pair <int , int>& b){
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second < b.second;
}
vector<pair<int , int>> order(vector<int> &monster, int k){
    int n = monster.size();
    vector<pair<int , int> >v(n);
    
    for(int i = 0; i < n; i++){
        if(monster[i] % k == 0)
            v[i] = {k , i + 1};
        else
            v[i] = {monster[i] % k , i + 1};
    }

    sort(v.begin() , v.end(), cmp);

    return v;

}
int main(){
    int T;
    cin >> T;

    while(T--){
        int n , k;
        cin >> n >> k;

        vector<int>monster(n);

        for(int i = 0; i < n; i++){
            cin >> monster[i];
        }

        vector<pair<int, int>> ans = order(monster, k );

        for(int i = 0; i < n; i++){
            cout << ans[i].second << " ";
        }

        cout << endl;
    }
}