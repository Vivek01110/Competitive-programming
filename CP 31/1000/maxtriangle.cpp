#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int w , h;
        cin >> w >> h;

        int k;
        cin >> k;

        int xmin = INT_MAX;
        int xmax = 0;

        int ymin = INT_MAX;
        int ymax = 0;


        for(int i = 0; i < k; i++){
            int x;
            cin >> x;

            xmin = min(xmin , x);
            xmax = max(xmax , x);
        }

        cin >> k;

        for(int i = 0; i < k; i++){
            int y;
            cin >> y;

            ymin = min(ymin , y);
            ymax = max(ymax , y);
        }

        cout << max(())

    }
}