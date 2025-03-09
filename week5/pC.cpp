#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> force(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (u < 0) {
            force[-u] = v;
        } else {
            adj[u].push_back(v);
        }
    }

    vector<char> stop(n + 1);
    vector<vector<char>> used(n + 1, vector<char>(2));
    auto dfs = [&](auto self, int u, bool bug) -> void {
        if (used[u][bug]) {
            return;
        }
        used[u][bug] = true;

        if (!force[u]) {
            stop[u] = true;
        } else {
            self(self, force[u], bug);
        }

        if (!bug) {
            for (int v: adj[u]) {
                self(self, v, true);
            }
        }
    };
    dfs(dfs, 1, false);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += stop[i];
    }
    cout << ans << '\n';
}