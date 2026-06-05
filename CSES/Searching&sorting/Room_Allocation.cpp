#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<tuple<int , int, int>> a(n);

    for(int i= 0; i < n; i++){
        int arr , dept;
        cin >> arr >> dept;

        a[i] = {arr , dept , i};
    }

    sort(a.begin(), a.end());
    

    int cnt = 1;
    vector<int> ans(n, 1);

    
    priority_queue<pair<int ,int> , vector<pair<int ,int>>, greater<pair<int , int>>>pq; // {depttime , roomno};

    pq.push({get<1>(a[0]),1});


    for(int i = 1; i < n; i++){
        auto [currarr , currdept , index] = a[i];

        auto[prevdept, roomno] = pq.top();

         if(currarr > prevdept){ 
            pq.pop();
            pq.push({currdept,roomno});
            ans[index] = roomno;
        }

         else{ 
             cnt++;
             pq.push({currdept, cnt}); 
             ans[index] = cnt;
        }       
    }

    cout << cnt << endl;

    for(int x : ans){
        cout << x << " ";
    }

}