#include <bits/stdc++.h>
using namespace std;

/*
Key Learnings points from this question are

1) As we already knoww that maxValue of x is 1e18 then max value of root(x) will
be 1e9 and thus we use our range to be [1,1e9]

2) if we do mid*mid <= x then it can go overflow as 1e18 * 1e18 will exceed the
range of long long [-1e18,1e18] that is why we use mid <= x/mid which saves us
from the overflow

3) The library function sqrt(x) does not gives accurate results

4) Time complexity of finding square root of n is log(n)

*/

long long findSqrtValue(long long x) {
    long long left = 1;
    long long right = 1e9;

    long long ans = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (mid <= x / mid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    // range of x = [1, 10^18]
    long long ans = findSqrtValue(10000);
    cout << ans << endl;

    return 1;
}