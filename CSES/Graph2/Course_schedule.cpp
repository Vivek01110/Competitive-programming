#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>>adj(n + 1);
    vector<int>indegree(n + 1 , 0);
    for(int i= 0;  i < m; i++){
        int a , b ;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int>q;
    int cnt = 0;
    for(int i = 1 ; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
             
        }
    }

    vector<int>ans;
    while(!q.empty()){
        int elm = q.front();
        q.pop();
        cnt++;  

        
        ans.push_back(elm);

        for(int nbr : adj[elm]){
            
            indegree[nbr]--;

            if(indegree[nbr] == 0){
                q.push(nbr); 
            }
        }
    } 

    if(cnt < n){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        
        for(int elm : ans){
            cout << elm << ' ';
        }
    }
}