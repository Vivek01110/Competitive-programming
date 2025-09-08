
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findMedian(vector<int>& arr, int left, int right) {
    sort(arr.begin() + left, arr.begin() + right + 1);
    return arr[left + (right - left) / 2];
}


int medianOfMedians(vector<int>& arr, int left, int right) {
    if (right - left < 5) {
        return findMedian(arr, left, right);
    }

    vector<int> medians;
    for (int i = left; i <= right; i += 5) {
        int subRight = min(i + 4, right);
        medians.push_back(findMedian(arr, i, subRight));
    }

    return medianOfMedians(medians, 0, medians.size() - 1);
}

int partition(vector<int>& arr, int left, int right, int pivot) {
    int pivotIndex = -1;
    
   
    for (int i = left; i <= right; i++) {
        if (arr[i] == pivot) {
            pivotIndex = i;
            break;
        }
    }
    
    
    swap(arr[pivotIndex], arr[right]);
    
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    
    swap(arr[i], arr[right]); 
    return i;
}


int kthSmallest(vector<int>& arr, int left, int right, int k) {
    if (left == right) return arr[left];

    int pivot = medianOfMedians(arr, left, right);
    int pivotIndex = partition(arr, left, right, pivot);
    
    int rank = pivotIndex - left + 1;

    if (rank == k) return arr[pivotIndex];
    else if (k < rank) return kthSmallest(arr, left, pivotIndex - 1, k);
    else return kthSmallest(arr, pivotIndex + 1, right, k - rank);
}


int main() {

    int T;
    cin >> T;

    while(T--){
        int k,n;
        cin >> k >> n;
        vector<int> arr;// = {12, 3, 5, 7, 19, 26, 23, 10, 15};

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        int kth_smallest_val = kthSmallest(arr, 0, arr.size() - 1, k);

        cout << kth_smallest_val << endl;
    }
    return 0;
}




 





