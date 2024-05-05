#include <bits/stdc++.h>
using namespace std;

/*
Find number of elements in the range of l to r in the array
example - Number of elements between 4 & 12
ans -> 6 => {3,5,6,7,8,10,11}
*/

int solve(int x, vector<int>& arr) {
  int left = 0;
  int right = arr.size() - 1;
  int ans = 0;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (arr[mid] < x) {
      ans = mid + 1;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {1, 2, 3, 5, 6, 7, 8, 10, 11, 16, 20};

  int ans = solve(12, arr) - solve(4, arr);

  cout << ans << endl;
}
