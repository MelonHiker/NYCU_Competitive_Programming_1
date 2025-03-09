#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    cnt[0] = 1;

    ll pre = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pre += x;
        ans += cnt[pre - 47];
        cnt[pre]++;
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}