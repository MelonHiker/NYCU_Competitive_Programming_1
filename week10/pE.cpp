#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(vector<ll> &bit, int pos, ll val) {
    for (; pos < bit.size(); pos += pos&-pos) {
        bit[pos] += val;
    }
}
ll get_sum(vector<ll> &bit, int pos) {
    ll sum = 0;
    for (; pos > 0; pos -= pos&-pos) {
        sum += bit[pos];
    }
    return sum;
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> bit(n + 1), bit2(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans += get_sum(bit2, n) - get_sum(bit2, a);
        update(bit2, a, get_sum(bit, n) - get_sum(bit, a));
        update(bit, a, 1);
    }
    cout << ans << '\n';
}