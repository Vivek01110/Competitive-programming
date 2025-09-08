#include<bits/stdc++.h>
using namespace std;

vector<int> nearlySortedArray(int  n, int k, vector<int> arr)
{
    priority_queue<int , vector<int> , greater<int>> pq;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(pq.size() > k)
        {
            int x = pq.top();
            pq.pop();
            ans.push_back(x);
        }
        pq.push(arr[i]);
    }
    while(!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        ans.push_back(x);
    }
    if(ans.size() == 0) cout << -1 ;
    return ans;
}

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n ;
        cin >>n;
        int k;
        cin >>k;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++) cin >> arr[i];

        vector<int> sorted(n,0);
        sorted = nearlySortedArray(n , k , arr);

        for(int i=0;i<n;i++)
        {
            cout << sorted[i] << " " ;
        }
        cout << endl;
    }
    return 0;
}

/*

test cases :
8
4 2
2 1 4 3
6 3
3 4 5 1 2 6
7 3
3 1 4 10000 600 200000000 30
6 4
1 2 3 4 5 6
5 3
2 2 2 2 2
6 6
8 7 9 3 2 1
6 0
2 3 5 6 8 9
0 3


Output:
1 2 3 4
1 2 3 4 5 6
1 3 4 30 600 10000 200000000
1 2 3 4 5 6
2 2 2 2 2
1 2 3 7 8 9
2 3 5 6 8 9
-1


*/