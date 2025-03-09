#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int da, db, max_depth = 0;
    vector<int> pre(n + 1);
    auto dfs = [&](auto self, int u, int par, int depth, bool flag) -> void {
        if (depth > max_depth) {
            if (flag) {
                db = u;
            } else {
                da = u;
            }
            max_depth = depth;
        }
        if (flag) {
            pre[u] = par;
        }
        for (int v: adj[u]) {
            if (v == par) {
                continue;
            }
            self(self, v, u, depth + 1, flag);
        }
    };
    dfs(dfs, 1, 0, 0, false);
    max_depth = 0;
    dfs(dfs, da, 0, 0, true);

    auto fp = [&](auto self, int root, int remove) -> tuple<int, int, int> {
        vector<pii> dp1(n + 1);
        vector<int> dp2(n + 1);
        auto dfs1 = [&](auto self, int u, int par) -> int {
            int mx1_n = 0, mx1 = 0, mx2 = 0;
            for (int v: adj[u]) {
                if (par == v) {
                    continue;
                }
                int depth = self(self, v, u) + 1;
                if (depth > mx1) {
                    mx2 = mx1;
                    mx1 = depth;
                    mx1_n = v;
                } else if (depth > mx2) {
                    mx2 = depth;
                }
            }
            dp1[u] = {mx1 ,mx1_n};
            dp2[u] = mx2;
            return mx1;
        };
        dfs1(dfs1, root, remove);
        int mn = 0, min_dis = n + 1, max_dis = 0;
        auto dfs2 = [&](auto self, int u, int par) -> void {
            if (dp1[u].first < min_dis) {
                min_dis = dp1[u].first;
                mn = u;
            }
            if (dp1[u].first > max_dis) {
                max_dis = dp1[u].first;
            }
            for (int v: adj[u]) {
                if (par == v) {
                    continue;
                }
                if (dp1[u].second == v) {
                    if (dp2[u] + 1 > dp1[v].first) {
                        dp2[v] = dp1[v].first;
                        dp1[v] = {dp2[u] + 1, u};
                    } else if (dp2[u] + 1 > dp2[v]) {
                        dp2[v] = dp2[u] + 1;
                    }
                } else {
                    dp2[v] = dp1[v].first;
                    dp1[v] = {dp1[u].first + 1, u};
                }
                self(self, v, u);
            }
        };
        dfs2(dfs2, root, remove);
        return {mn, min_dis, max_dis};
    };

    int old_a, old_b, new_a, new_b, new_dm = max_depth;
    for (da = pre[db]; da; da = pre[da], db = pre[db]) {
        auto x = fp(fp, da, db);
        auto y = fp(fp, db, da);
        int dm = max(get<1>(x) + get<1>(y) + 1, max(get<2>(x), get<2>(y)));
        if (dm < new_dm) {
            new_dm = dm;
            old_a = da;
            old_b = db;
            new_a = get<0>(x);
            new_b = get<0>(y);
        }
    }
    cout << new_dm << '\n';
    cout << old_a << ' ' << old_b << '\n';
    cout << new_a << ' ' << new_b << '\n';
}