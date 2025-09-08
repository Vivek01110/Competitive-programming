#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;
    for (int num : nums) {
        maxHeap.push(num);
        
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << findKthSmallest(nums, k) << endl;
    }
    return 0;
}