#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
       
        int n = items.size();
        vector<int> fc(n,0);//total items it gives us 
        vector<int> cost(n,0);
        int mincost = INT_MAX;
        int mincosti = -1;
        for (int i = 0; i < n; i++) {
            int fi = items[i][0];
            cost[i] = items[i][1];
            if (cost[i] < mincost) {
                mincost = cost[i];
                mincosti = i;
            }
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                int fj = items[j][0];
                if (fj % fi == 0)
                    fc[i]++;
            }
        }
         int singlebuy=0;
        for(int i =0;i<n;i++){
            singlebuy=max(singlebuy,budget/cost[i]);
        }
        vector<pair<double,int>> v;//fc/cost,index
        for(int i =0;i<n;i++){
            int freecopy=fc[i];
            if(freecopy==0) continue;
            v.push_back({(double)(freecopy+1)/(double)cost[i],i});
        }
        sort(v.rbegin(),v.rend());
        int bounded =0;
        int ans =budget/mincost;
        for(int i =0;i<v.size();i++){
            int idx=v[i].second;
            int c=cost[idx];
            int freecopy=fc[idx];
            if(budget>=c){
                budget-=c;
                bounded+=freecopy+1;
                // bounded+=1;
            }
            ans=max(ans,bounded+budget/mincost);
        }
        // if(budget>=mincost){
        //     ans+=budget/mincost;
        // }
        return max(ans,singlebuy);      
        
    }
}; 