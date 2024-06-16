#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

Problem -> Packing Rectangles ( CodeForces )
link ->
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

-? We have to find the min side of square such that we can fit n rectangles of
height h and width w

-> Key Points from this problem

1) If we use this rows * columns >= n in possible function then it can cause the
overflow

h = 1, w = 1, side = 1e18 and we will get 1e18 * 1e18 = 1e36 and we can't fit it
in long long

So instead we use this rows >= (n / columns) but here is a catch that here we
require the ceil value of (n/columns) to satisfy equality

* ceil(a/b) = (a+b-1)/b

*/

bool possible(ll side, ll w, ll h, ll n) {
  ll rows = side / h;
  ll columns = side / w;

  if (columns > 0 && rows >= (n + columns - 1) / columns) {
    return true;
  }

  return false;
}

void main() {
  ll w, h, n;

  cin >> w >> h >> n;

  ll left = 0;
  ll right = max(w, h) * n;

  ll side = -1;

  while (left <= right) {
    ll mid = left + (right - left) / 2;

    if (possible(mid, w, h, n)) {
      side = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << side << endl;
}