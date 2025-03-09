#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> par;
int get(int x) {
    if (par[x] == x) return x;
    return par[x] = get(par[x]);
}
void join(int px, int py) {
    par[px] = py;
}
struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edges.push_back({i, j, grid[i][j]});
        }
    }
    sort(edges.begin(), edges.end());

    par.resize(n + 1);
    iota(par.begin(), par.end(), 0);
    vector<pii> ans;
    for (auto e: edges) {
        int px = get(e.u), py = get(e.v);
        if (px != py) {
            join(px, py);
            ans.push_back({e.u, e.v});
        }
    }

    for (auto p: ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}