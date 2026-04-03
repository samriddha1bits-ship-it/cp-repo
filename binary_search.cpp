// Problem: Binary Search
// Approach: Standard binary search on sorted array
// Time Complexity: O(log n)


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Found target
        if (arr[mid] == target) {
            cout << "Found at index: " << mid << endl;
            return 0;
        }
        // Move right
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // Move left
        else {
            right = mid - 1;
        }
    }

    cout << "Not found" << endl;
    return 0;
}
