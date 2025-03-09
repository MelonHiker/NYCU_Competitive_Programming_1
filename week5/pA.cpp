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
void merge(int x, int y) {
    x = get(x), y = get(y);
    par[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (get(u) != get(v)) {
            merge(u, v);
        }
    }
    bool connected = true;
    for (int i = 2; i <= n; i++) {
        if (get(1) != get(i)) {
            cout << i << '\n';
            connected = false;
        }
    }
    if (connected) {
        cout << "Connected\n";
    }
}