#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int par;
        cin >> par;
        if (par) {
            adj[par].push_back(i);
        }
    }

    int timer = 0;
    vector<char> used(n + 1);
    vector<int> in(n + 1), out(n + 1);
    auto dfs = [&](auto self, int u) -> void {
        used[u] = true;
        in[u] = ++timer;
        for (int v: adj[u]) {
            self(self, v);
        }
        out[u] = timer;
    };
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(dfs, i);
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        vector<pii> prs(m);
        for (pii &pr: prs) {
            int box;
            cin >> box;
            pr = {in[box], out[box]};
        }
        sort(prs.begin(), prs.end(), [](pii a, pii b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        int ans = 0, pre = 0;
        for (const pii &pr: prs) {
            if (pr.first <= pre) {
                continue;
            }
            ans += pr.second - pr.first + 1;
            pre = pr.second;
        }
        cout << ans << '\n';
    }
}