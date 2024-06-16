#include <bits/stdc++.h>
using namespace std;

typedef double d;
typedef long long ll;

/*
Calculating the square root of the value in decimals
In these type of questions we are given the precision value that how much
precision difference can our answers vary and will be accepted

Also the time complexity of binary search on the decimals values is
TC = log( Integer Search Space * 1/Precision )
*/

/*
With the max range value and the precision value we find the worst time
complexity and we use below values to find estimated count

log(10^3) = 10;
log(10^6) = log(10^3 * 10^3) = log(10^3) + log(10^3) = 20;
log(10^9) = 30
log(10^12) = 40
log(10^15) = 50;
log(10^18) = 60
log(10^21) = 70
log(10^24) = 80 and so on


and in below problem we assume the max range value will be 1e20 and precision is
1e-7 so our worst case will be 1e27 and it will be approximate to 90 iterations;
We can even run for more than 90 iterations and it won't cause issue keeping in
mind that overall time complexity should be acceptable

*/
int accuratefindSqrt(d value, d precision) {
  d left = 1;
  d right = 1e20;

  d ans = 0;

  for (int count = 0; count <= 90; count++) {
    d mid = left + (right - left) / 2;

    if (mid <= value / mid) {
      ans = mid;
      left = mid + precision;
    } else {
      right = mid - precision;
    }
  }

  cout << "Ans: " << ans << endl;
}

/* This function on big values can cause stack overflow as double has a global
precision issue and after a certain point the double cannot store and compare
accurate values and thus we should prefer for loops with estimated iteration
count instead of while loop
*/

int naivefindSqrt(d value, d precision) {
  d left = 1;
  d right = 1e20;

  d ans = 0;

  while (right - left > precision) {
    d mid = left + (right - left) / 2;

    if (mid <= value / mid) {
      ans = mid;
      left = mid + precision;
    } else {
      right = mid - precision;
    }
  }

  cout << "Ans: " << ans << endl;
}

int main() {
  d precision = 1e-7;
  d value = 31.00;
  cout << setprecision(7) << fixed;

  naivefindSqrt(value, precision);
  accuratefindSqrt(value, precision);
}