#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> par;
int get(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = get(par[x]);
}
void join(int x, int y) {
    x = get(x), y = get(y);
    par[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    par.resize(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    while (q--) {
        char t;
        cin >> t;
        int u, v;
        cin >> u >> v;
        if (t == '=') {
            join(u, v);
        } else {
            if (get(u) == get(v)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
}