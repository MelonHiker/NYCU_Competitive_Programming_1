#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    int logn = __lg(n);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(logn + 1));
    auto dfs = [&](auto self, int u, int par) -> void {
        dp[u][0] = par;
        depth[u] = depth[par] + 1;
        for (int j = 1; j <= logn; j++) {
            dp[u][j] = dp[dp[u][j - 1]][j - 1];
        }
        for (int v: adj[u]) {
            if (v == par) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    auto lca = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        for (int diff = depth[u] - depth[v], j = 0; diff; diff>>=1, j++) {
            if (diff & 1) {
                u = dp[u][j];
            }
        }
        if (u == v) {
            return u;
        }
        for (int j = logn; j >= 0; j--) {
            if (dp[u][j] != dp[v][j]) {
                u = dp[u][j];
                v = dp[v][j];
            }
        }
        return dp[u][0];
    };

    while (q--) {
        int r, p;
        cin >> r >> p;
        int l = lca(r, p);
        ll k = depth[r] + depth[p] - 2 * depth[l] + 1;
        cout << n + (k - 1) * k / 2 << '\n';
    }
}