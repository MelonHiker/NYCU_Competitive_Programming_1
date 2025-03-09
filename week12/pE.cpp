#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), radj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vector<int> stk;
    vector<char> used(n + 1);
    auto dfs1 = [&](auto self, int u) -> void {
        used[u] = true;
        for (int v: adj[u]) {
            if (used[v]) {
                continue;
            }
            self(self, v);
        }
        stk.push_back(u);
    };
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            continue;
        }
        dfs1(dfs1, i);
    }

    int id = 0;
    vector<int> scc(n + 1, -1);
    vector<vector<int>> group;
    auto dfs2 = [&](auto self, int u) -> void {
        scc[u] = id;
        group.back().push_back(u);
        for (int v: radj[u]) {
            if (scc[v] != -1) {
                continue;
            }
            self(self, v);
        }
    };
    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        if (scc[u] == -1) {
            group.push_back({});
            dfs2(dfs2, u);
            id++;
        }
    }

    used.assign(n + 1, false);
    unordered_map<int, unordered_map<int, int>> dist;
    auto dfs = [&](auto self, int u, int st, int d) -> void {
        dist[st][u] = max(dist[st][u], d);
        used[u] = true;
        for (int v: adj[u]) {
            if (used[v] || scc[u] != scc[v]) {
                continue;
            }
            self(self, v, st, d + 1);
        }
        used[u] = false;
    };
    vector<int> dp(n + 1, 1), dp1(n + 1);
    for (auto gp: group) {
        dist.clear();
        for (int u: gp) {
            dfs(dfs, u, u, 0);
        }
        for (int x: gp) {
            for (int y: gp) {
                if (scc[x] == scc[y]) {
                    dp1[y] = max(dp1[y], dp[x] + dist[x][y]);
                }
            }
        }
        for (int u: gp) {
            dp[u] = dp1[u];
            dp1[u] = 0;
            for (int v: adj[u]) {
                if (scc[u] != scc[v]) {
                    dp[v] = max(dp[v], dp[u] + 1);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}