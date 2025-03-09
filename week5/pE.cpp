#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<ll> par, sz, sum;
    DSU(int _size): par(_size * 2 + 1), sz(_size * 2 + 1, 1), sum(_size * 2 + 1) {
        for (int i = 1; i <= _size; i++) {
            par[i] = i + _size;
            par[i + _size] = i + _size;
            sum[i] = i;
            sum[i + _size] = i;
        }
    }
    int get(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = get(par[x]);
    }
    void join(int x, int y) {
        int px = get(x), py = get(y);
        if (px == py) {
            return;
        }
        if (sz[px] < sz[py]) {
            par[px] = py;
            sz[py] += sz[px];
            sum[py] += sum[px];
        } else {
            par[py] = px;
            sz[px] += sz[py];
            sum[px] += sum[py];
        }
    }
    void move(int x, int y) {
        int px = get(x), py = get(y);
        if (px == py) {
            return;
        }
        par[x] = py;
        sz[px]--, sz[py]++;
        sum[px]-=x, sum[py]+=x; 
    }
};

void solve(int n) {
    DSU dsu(n);

    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, q;
            cin >> p >> q;
            dsu.join(p, q);
        } else if (t == 2) {
            int p, q;
            cin >> p >> q;
            dsu.move(p, q);
        } else if (t == 3) {
            int p;
            cin >> p;
            int px = dsu.get(p);
            cout << dsu.sz[px] << ' ' << dsu.sum[px] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        solve(n);
    }
}