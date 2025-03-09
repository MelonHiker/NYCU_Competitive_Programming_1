#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, string>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    stringstream ss;
    map<string, int> in;
    map<string, vector<string>> adj;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        ss << line;
        
        string u, v;
        ss >> u;
        u.pop_back();
        while (ss >> v) {
            adj[v].push_back(u);
            in[u]++;
        }
        ss.str("");
        ss.clear();
    }

    string modify;
    cin >> modify;
    queue<string> que;
    for (const auto &par: adj) {
        if (in[par.first] == 0) {
            que.push(par.first);
        }
    }
    int idx = 0;
    map<string, int> topo;
    while (!que.empty()) {
        string u = que.front();
        que.pop();
        topo[u] = idx++;
        for (const string &v: adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                que.push(v);
            }
        }
    }
    set<string> used;
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({topo[modify], modify});
    used.insert(modify);
    while (!pq.empty()) {
        pr u = pq.top();
        pq.pop();
        cout << u.second << '\n';
        for (const string &v: adj[u.second]) {
            if (used.count(v)) {
                continue;
            }
            pq.push({topo[v], v});
            used.insert(v);
        }
    }
}