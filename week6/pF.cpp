#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> bit;
ll get_sum(int pos) {
    ll sum = 0;
    for (; pos > 0; pos -= pos&-pos) {
        sum += bit[pos];
    }
    return sum;
}
void update(int pos, ll delta) {
    for (; pos < bit.size(); pos += pos&-pos) {
        bit[pos] += delta;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    bit.resize(n + 1);
    while (q--) {
        char c;
        cin >> c;
        if (c == '+') {
            int i;
            ll delta;
            cin >> i >> delta;
            i++;
            update(i, delta);
        } else if (c == '?') {
            int i;
            cin >> i;
            cout << get_sum(i) << '\n';
        }
    }    
}