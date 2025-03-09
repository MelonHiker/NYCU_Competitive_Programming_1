#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        int canva;
        cin >> canva;
        pq.push(canva);
    }
    ll ans = 0;
    while (pq.size() > 1) {
        ll u = pq.top();
        pq.pop();
        ll v = pq.top();
        pq.pop();
        ans += u + v;
        pq.push(u + v);
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