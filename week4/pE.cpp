#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ld ans = 1, rk = 1;
    for (int i = 1; i <= n; i++) {
        rk *= 1 / ld(i);
        ans += rk;
    }
    cout << fixed << setprecision(15) << ans << '\n';
}