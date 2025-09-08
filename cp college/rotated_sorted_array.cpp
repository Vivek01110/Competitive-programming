//find an element in rotated sorted array

#include<bits/stdc++.h>
using namespace std;

// 4 5 6 7 1 2 3 

int binary_search(vector<int> &arr , int target){
    int n = arr.size();

    if(target == arr[0])
        return 0;
    
    int s = 0;
    int e = n - 1;

    int mid = s +  (e - s)/2;

    while(s <= e){
            // if mid elm is target
            if(arr[mid] == target){
                return mid;
            }
          // if target is in first region and mid is less than target
            if(arr[mid] < target && target > arr[0]){
                //if mid is in first region
                if(arr[mid] < arr[0])
                    e = mid - 1;
    
                // mid is in second region
                else{
                    s = mid + 1; // mid > arr[0]
                }
            }
            // target is in second region and mid is less than target
            else if(arr[mid] < target && target < arr[0]){
                s = mid + 1;
            }
            //target is in second region and mid is greater than target
            else if(arr[mid] > target && target < arr[0]){
                // mid is in first region
                if(arr[mid] >= arr[0]){
                    s = mid + 1;
                }
                //mid is in second region
                else{
                    e = mid - 1;
                }
            }

            else{
                e = mid - 1;
            }
            mid = s +  (e - s)/2;
            
        }
        
        return -1;
    }

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,target;

        cin >> n >> target;

        vector<int> arr(n);

        for(int i=0; i < n; i++){
            cin >> arr[i];
        }

        cout << binary_search(arr , target) << endl;
    }
}

/*
5
5
6
14  15 16 1 2
13
5
15 17 19 20 25 30 35 40 1 3 5 7 10
4
6
4 5 6 1
6
6
4 5 6 1 2 3
5
2
4 5 1 2 3
2
1
2 1
2
2
1 2
4
12
10 12 14 18

*/


