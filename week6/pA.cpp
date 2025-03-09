#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }

    int st, ed;
    cin >> st >> ed;

    vector<vector<pii>> fadj= adj;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        fadj[n].push_back({0, x});
    }

    vector<int> sdist(n + 1, INF);
    sdist[n] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, n});
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if (cur.first > sdist[cur.second]) {
            continue;
        }
        for (pii nxt: fadj[cur.second]) {
            if (nxt.first + sdist[cur.second] >= sdist[nxt.second]) {
                continue;
            }
            sdist[nxt.second] = nxt.first + sdist[cur.second];
            pq.push({sdist[nxt.second], nxt.second});
        }
    }

    auto ck = [&](int thr) {
        if (sdist[st] < thr) {
            return false;
        }
        vector<int> dist(n, INF);
        dist[st] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, st});
        while (!pq.empty()) {
            pii cur = pq.top();
            pq.pop();
            if (cur.second == ed) {
                break;
            }
            if (cur.first > dist[cur.second]) {
                continue;
            }
            for (pii nxt: adj[cur.second]) {
                if (sdist[nxt.second] < thr || nxt.first + dist[cur.second] >= dist[nxt.second]) {
                    continue;
                }
                dist[nxt.second] = nxt.first + dist[cur.second];
                pq.push({dist[nxt.second], nxt.second});
            }
        }
        return dist[ed] <= t;
    };

    int l = 0, r = INF;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ck(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << '\n';
}