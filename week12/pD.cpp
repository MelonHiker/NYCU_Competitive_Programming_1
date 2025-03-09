#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, p, x, l;
    cin >> c >> p >> x >> l;

    vector<int> patner(c + 1);
    vector<set<int>> adj(c + 1);
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        patner[u]++;
        patner[v]++;
    }
    vector<char> leave(c + 1);
    queue<int> que;
    que.push(l);
    leave[l] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v: adj[u]) {
            adj[v].erase(u);
            if (!leave[v] && adj[v].size() <= patner[v] / 2) {
                que.push(v);
                leave[v] = true;
            }
        }
    }
    if (leave[x]) {
        cout << "leave\n";
    } else {
        cout << "stay\n";
    }
}