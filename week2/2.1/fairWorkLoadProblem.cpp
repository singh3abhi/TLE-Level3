#include <bits/stdc++.h>
using namespace std;

/*
FairWorkload Problem

Given an array of workloads, split it among k workers such th at the maximum
work that any worker has to do is minimized  ( Arr need not to be sorted )


search space 0 to 10^6
optimal search space = max of array to sum of all elements of array
Time complexity = Log(search space) * O(n)

*/

bool possible(int x, vector<int> a, int k) {
  int usedWorkers = 1;
  int currentWorkersWorkload = 0;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] > x) {
      return false;
    }
    if (a[i] + currentWorkersWorkload <= x) {
      currentWorkersWorkload += a[i];
    } else {
      if (usedWorkers == k)
        return false;
      usedWorkers++;
      currentWorkersWorkload = 0;
      currentWorkersWorkload += a[i];
    }
  }
  return true;
}

int main() {
  vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int k = 3;

  int left = 0;     // max of the arr
  int right = 1e6;  // sum of all elements of array

  int ans = 0;
  while (left <= right) {
    int mid = (left + right) / 2;

    if (possible(mid, arr, k)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << ans << endl;
}