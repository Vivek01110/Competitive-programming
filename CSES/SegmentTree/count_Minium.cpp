    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define MOD 1000000007
    struct Node{
        int mini;
        int cnt;  
    };

    class SegmentTree{
        private:
        Node merge(Node &a , Node &b){
            if(a.mini < b.mini) return a;
            if(a.mini > b.mini) return b;
            
            return {a.mini , a.cnt + b.cnt};
        }
        public:
        vector<Node> tree;
        vector<int>arr;
        int n;

        SegmentTree(int n , vector<int> arr){
            this->arr = arr;
            this->n = n;

            tree.resize(4*n);
            for(int i = 0; i < 4*n; i++){
                tree[i] =  Node();
            }
        }
        
        void build(int i , int l , int r , vector<int>&a){
            if(l == r){
                tree[i].mini = a[l];
                tree[i].cnt = 1;
                return;
            }

            int mid = ( l + r)/2;

            build(2*i + 1 , l , mid , a );
            build(2*i + 2 , mid + 1 , r , a);

            
            // both child have same minimum add their cnt
            tree[i] = merge(tree[2*i + 1], tree[2*i + 2]);
            
        }

        Node query(int i , int l , int r , int ql , int qr){
            if(r < ql || l > qr)    
                return {INT_MAX , 0};

            if(ql <= l && r <= qr){
                return tree[i];
            }

            int mid = (l + r)/2;

            Node left = query(2*i + 1 , l , mid, ql , qr);
            Node right = query(2*i + 2 , mid + 1 , r , ql ,qr);
            Node* ans = new Node();

            if(left.mini == right.mini)
                return {left.mini, left.cnt + right.cnt};

            else if(left.mini < right.mini)
                return {left.mini , left.cnt};   
            else
                return {right.mini,  right.cnt};
            
        }

        void query_update(int i , int l , int r , int pos , int val ,   vector<int>&a){
            if(l == r){
                tree[i].mini = val;
                tree[i].cnt = 1;
                a[pos] = val;
                return;
            }

            int mid = (l + r)/2;

            if(pos <= mid){
                query_update(2*i + 1 , l , mid , pos , val , a );
            }
            else{
                query_update(2*i + 2 , mid + 1 , r , pos , val , a);
            }

            tree[i] = merge(tree[2*i + 1] , tree[2*i + 2]);
        }
    };
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n, m;
        cin >> n >> m;

        vector<int>arr(n);

        for(int i=0; i < n; i++){
            cin >> arr[i];
        }

        SegmentTree sg(n,arr);
        sg.build(0,0,n-1,arr);

        for(int i = 0; i < m; i++){
            int t , a, b;
            cin >> t >> a >> b;

            if(t == 1){
                sg.query_update(0,0, n - 1 , a, b,arr);
            }
            else{
                Node ans = sg.query(0, 0, n -1, a, b - 1);

                cout << ans.mini <<" " <<  ans.cnt << endl; 
            }
        }
    }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define MOD 1000000007
// class Node{
//     public:
//     int mini;
//     int cnt;
    
//     Node(){
//         this ->cnt= 0;
//         this -> mini = INT_MAX;
//     }
// };

// class SegmentTree{
//     public:
//     vector<Node*> tree;
//     vector<int>arr;
//     int n;

//     SegmentTree(int n , vector<int> arr){
//         this->arr = arr;
//         this->n = n;

//         tree.resize(4*n);
//         for(int i = 0; i < 4*n; i++){
//             tree[i] = new Node();
//         }
//     }
//     void build(int i , int l , int r , vector<int>&a){
//         if(l == r){
//             tree[i] -> mini = a[l];
//             tree[i] ->cnt = 1;
//             return;
//         }

//         int mid = ( l + r)/2;

//         build(2*i + 1 , l , mid , a );
//         build(2*i + 2 , mid + 1 , r , a);

        
//         // both child have same minimum add their cnt
//         if(tree[2*i + 1] ->mini == tree[2*i + 2] ->mini){
//             tree[i] ->mini = tree[2*i + 1] ->mini;
//             tree[i]->cnt = tree[2*i + 1]->cnt + tree[2*i + 2]->cnt;
//         }
//         else if(tree[2*i + 1]->mini < tree[2*i + 2]->mini){
//             tree[i]->cnt = tree[2*i + 1]->cnt;
//             tree[i]->mini = tree[2*i + 1]->mini;
//         }
//         else{
//             tree[i]->cnt = tree[2*i + 2]->cnt;
//             tree[i]->mini = tree[2*i + 2]->mini;
//         }
//     }

//     Node* query(int i , int l , int r , int ql , int qr){
//         if(r < ql || l > qr)    
//             return new Node();

//         if(ql <= l && r <= qr){
//             return tree[i];
//         }

//         int mid = (l + r)/2;

//         Node* left = query(2*i + 1 , l , mid, ql , qr);
//         Node* right = query(2*i + 2 , mid + 1 , r , ql ,qr);
//         Node* ans = new Node();

//         if(left ->mini == right ->mini){
//             ans->mini = left -> mini;
//             ans -> cnt = left -> cnt + right-> cnt;
//         }
//         else if(left ->mini < right ->mini){
//             ans->mini = left -> mini;
//             ans -> cnt = left -> cnt;
//         }
//         else{
//             ans->mini = right -> mini;
//             ans -> cnt = right -> cnt;
//         }

//         return ans;
//     }

//     void query_update(int i , int l , int r , int pos , int val ,   vector<int>&a){
//         if(l == r){
//             tree[i] -> mini = val;
//             tree[i] -> cnt = 1;
//             a[pos] = val;
//             return;
//         }

//         int mid = (l + r)/2;

//         if(pos <= mid){
//             query_update(2*i + 1 , l , mid , pos , val , a );
//         }
//         else{
//             query_update(2*i + 2 , mid + 1 , r , pos , val , a);
//         }

//         if(tree[2*i + 1] ->mini == tree[2*i + 2] ->mini){
//             tree[i] ->mini = tree[2*i + 1] ->mini;
//             tree[i]->cnt = tree[2*i + 1]->cnt + tree[2*i + 2]->cnt;
//         }
//         else if(tree[2*i + 1]->mini < tree[2*i + 2]->mini){
//             tree[i]->cnt = tree[2*i + 1]->cnt;
//             tree[i]->mini = tree[2*i + 1]->mini;
//         }
//         else{
//             tree[i]->cnt = tree[2*i + 2]->cnt;
//             tree[i]->mini = tree[2*i + 2]->mini;
//         }
//     }
// };
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     vector<int>arr(n);

//     for(int i=0; i < n; i++){
//         cin >> arr[i];
//     }

//     SegmentTree sg(n,arr);
//     sg.build(0,0,n-1,arr);

//     for(int i = 0; i < m; i++){
//         int t , a, b;
//         cin >> t >> a >> b;

//         if(t == 1){
//             sg.query_update(0,0, n - 1 , a, b,arr);
//         }
//         else{
//             Node* ans = sg.query(0, 0, n -1, a, b - 1);

//             cout << ans -> mini <<" " <<  ans -> cnt << endl; 
//         }
//     }
// }