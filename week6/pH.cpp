#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int cnt[7] = {};
    Node operator+(const Node &other) {
        Node res;
        for (int i = 1; i <= 6; i++) {
            res.cnt[i] = cnt[i] + other.cnt[i];
        }
        return res;
    }
    Node operator-(const Node &other) {
        Node res;
        for (int i = 1; i <= 6; i++) {
            res.cnt[i] = cnt[i] - other.cnt[i];
        }
        return res;
    }
};
vector<Node> bit;
Node get_sum(int pos) {
    Node sum;
    for (; pos > 0; pos -= pos&-pos) {
        sum = sum + bit[pos];
    }
    return sum;
}
void update(int pos, int pre, int cur) {
    for (; pos < bit.size(); pos += pos&-pos) {
        bit[pos].cnt[pre]--;
        bit[pos].cnt[cur]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> value(7);
    for (int i = 1; i <= 6; i++) {
        cin >> value[i];
    }

    bit.resize(n + 1);
    vector<int> gem(n + 1);
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        gem[i] = c - '0';
        bit[i].cnt[gem[i]]++;
        int nxt = i + (i&-i);
        if (nxt <= n) {
            bit[nxt] = bit[nxt] + bit[i];
        }
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, p;
            cin >> k >> p;
            update(k, gem[k], p);
            gem[k] = p;
        } else if (t == 2) {
            int p, v;
            cin >> p >> v;
            value[p] = v;
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            Node res = get_sum(r) - get_sum(l - 1);
            ll ans = 0;
            for (int i = 1; i <= 6; i++) {
                ans += res.cnt[i] * value[i];
            }
            cout << ans << '\n';
        }
    }    
}