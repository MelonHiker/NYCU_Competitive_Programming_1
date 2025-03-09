#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> par, sz;
int get(int x) {
    if (par[x] == x) return x;
    return par[x] = get(par[x]);
}
void join(int a, int b) {
    if (sz[a] < sz[b]) {
        par[a] = b;
        sz[b] += sz[a];
    } else {
        par[b] = a;
        sz[a] += sz[b];
    }
}
struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

void solve(int n, int m) {
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v) {
            if (u > v) swap(u, v);
            edges.push_back({u, v, w});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    par.resize(n);
    sz.assign(n, 1);
    iota(par.begin(), par.end(), 0);
    
    ll totalWeight = 0;
    vector<pii> ans_edges;
    int countEdges = 0;
    
    for (auto &e : edges) {
        int pu = get(e.u), pv = get(e.v);
        if (pu != pv) {
            join(pu, pv);
            totalWeight += e.w;
            ans_edges.push_back({e.u, e.v});
            countEdges++;
        }
    }
    
    if (n > 1 && countEdges != n - 1) {
        cout << "Impossible\n";
        return;
    }
    
    sort(ans_edges.begin(), ans_edges.end());
    
    cout << totalWeight << "\n";
    for (auto &p : ans_edges) {
        cout << p.first << " " << p.second << "\n";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        solve(n, m);
    }
    return 0;
}