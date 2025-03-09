#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, a, c;
    cin >> n >> m >> a >> c;
    vector<ll> x(n + 1);
    cin >> x[0];
    for (int i = 1; i <= n; i++) {
        x[i] = (a * x[i - 1] + c) % m;
    }

    auto ck = [&](ll k) -> bool {
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid < 1 || mid > n) {
                return false;
            }
            if (x[mid] == k) {
                return true;
            } else if (x[mid] < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ck(x[i])) {
            ans++;
        }
    }
    cout << ans << '\n';
}