#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int mod = 9901;


void solve(int case_idx) {
    int n, k;
    cin >> n >> k;
    vector<vector<char>> forbid(n + 1, vector<char>(n + 1));
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        forbid[u][v] = forbid[v][u] = true;
    }
    map<pii, int> edge;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (forbid[i][j]) {
                continue;
            }
            edge[{i, j}];
        }
    }
    int idx = 0;
    for (auto &pr: edge) {
        pr.second = idx++;
    }

    int ans = 0;
    bitset<45> cur_edge;
    unordered_set<bitset<45>> ans_edge;
    vector<char> used(n + 1);
    auto dfs = [&](auto self, int u=1, int cnt=0) -> void {
        if (used[u]) {
            if (u == 1 && cnt == n && !ans_edge.count(cur_edge)) {
                ans_edge.insert(cur_edge);
                ans++;
            }
            if (ans >= mod) {
                ans -= mod;
            }
            return;
        }
        used[u] = true;
        for (int v = 1; v <= n; v++) {
            if (u == v || forbid[u][v]) {
                continue;
            }
            int id;
            if (u < v) {
                id = edge[{u, v}];
            } else {
                id = edge[{v, u}];
            }
            if (!cur_edge[id]) {
                cur_edge.set(id);
                self(self, v, cnt + 1);
                cur_edge.reset(id);
            }
        }
        used[u] = false;
    };
    dfs(dfs);
    cout << "Case #" << case_idx << ": " << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}