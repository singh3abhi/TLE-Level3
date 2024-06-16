#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vpii;
typedef vector<pdd> vpdd;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;

/*
Problem Link ->
https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
*/

bool possible(double time, vpdd& arr, int n) {
    pdd curr = {-1e18, 1e18};

    for (auto val : arr) {
        double position = val.first;
        double speed = val.second;

        pdd range = {position - (speed * time), position + speed * time};

        curr = {max(curr.first, range.first), min(curr.second, range.second)};

        if (curr.first > curr.second) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vpdd arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    double eps = 1e-7;
    double left = 0;
    double right = 1e9;

    // log(10^16) ~= 70
    int count = 70;
    double ans;

    for (int i = 0; i <= count; i++) {
        double mid = left + (right - left) / 2;

        if (possible(mid, arr, n)) {
            ans = mid;
            right = mid - eps;
        } else {
            left = mid + eps;
        }
    }

    cout << setprecision(7) << fixed << ans;
}