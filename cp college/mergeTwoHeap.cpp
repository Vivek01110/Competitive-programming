#include<bits/stdc++.h>
using namespace std;

void Heapify(vector<int> &arr , int index){
    int n = arr.size();
    int largest = index;


    int left = 2*index;
    int right = 2*index + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != index){
        swap(arr[largest] , arr[index]);
        Heapify(arr , largest);
    }
}

void Build_Heap(vector<int>&A){
    int n = A.size() + 1;
    
    for(int i = n/2; i >= 1; i--){
        Heapify(A , i);
    }
}

void print(vector<int>A){
    for(int i = 1; i < A.size(); i++){
        cout << A[i] << " ";
    }

    cout << endl;

}
void merge(vector<int>& A,vector<int>&B, int m , int n){
      if(m == 0){
            print(B);
      }
      if(n == 0){
        print(A);
      }

      for(int i = 1; i <= n; i++){
         A.push_back(B[i]);
      }

      Build_Heap(A);
    
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int m, n;
        cin >> m >> n;

        vector<int>A(m + 1);
        vector<int>B(n + 1);

        for(int i = 1; i <= m; i++){
            cin >> A[i];
        }

        for(int i = 1; i <= n; i++){
            cin >> B[i];
        }

        Build_Heap(A);
        Build_Heap(B);

        merge(A, B, m , n);
        
        print(A);

       
    }
}


/*
2
3 3
5 4 3
2 1 0
7 3
5 5 4 1 3 3 2
6 3 2
3 3
3 2 1
3 2 1
1 3
3
2 1 0
0 2
2 1
3 0
2 0 1
4 3
10 20 30 40
50 60 70 
*/