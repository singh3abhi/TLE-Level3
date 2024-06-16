#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

typedef vector<double> vd;

/*
Problem Link ->
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
*/

bool possible(double mid, vd& arr, ll n, ll k) {
    ll totalPieces = 0;

    for (int i = 0; i < n; i++) {
        totalPieces += arr[i] / mid;

        if (totalPieces >= k) {
            return true;
        }
    }

    return false;
}

void solve(ll test_case) {
    ll n, k;
    cin >> n >> k;

    vd arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    double eps = 1e-7;

    double left = eps;
    double right = 1e7;

    double res = -1;

    for (int i = 0; i <= 50; i++) {
        double mid = left + (right - left) / 2;

        if (possible(mid, arr, n, k)) {
            res = mid;
            left = mid + eps;
        } else {
            right = mid - eps;
        }
    }

    // This setting precision is very much needed otherwise compiler will print
    // approximate answers and it might fail a test case
    cout << setprecision(7) << fixed;
    cout << res << endl;
}

int main() {
    solve(1);
}